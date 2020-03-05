#include "foo.h"
#include <fstream>
#include<iostream>
#include<string>
#include <sstream> 
#include <direct.h>
#include <io.h>
#include <windows.h>
#include <TlHelp32.h>
#include <vector>
using namespace std;



void create_dynamic(int **arr, int games, int competitors)
{
	for (int i = 0; i < games; i++)
	{
		arr[i] = new int[competitors] {};
	}
}

void delete_dynamic(int*** arr, int games, int teams)
{
	for (int i = 0; i < teams; i++)
	{
		for (int j = 0; j < games; j++)
		{
			delete[] arr[i][j];
		}
	}
	delete arr;
}

void delete_array(string *teams)
{
	delete[] teams;
}

void delete_array(int* result)
{
	delete[] result;
}

void data_points(int*** arr, int games, int competitors, int* results, int from, int to)
{
	for (int i = from; i < to; i++)
	{

		for (int j = 0; j < games; j++)
		{

			for (int k = 0; k < competitors; k++)
			{
				if (arr[i][j][k] > arr[i][j][k + 1]) {
					results[i] += 3;
				}
				if (arr[i][j][k] = arr[i][j][k + 1]) {
					results[i] += 1;
				}


			}

		}

	}
}
void output_results(int*** arr, int games, int competitors, int* results, string* teams, int sum) //вывод
{
	cout << "Результати: " << endl;
	for (int i = 0; i < sum; i++)
	{
		cout << teams[i] << " : " << results[i] << endl;


	}
}



void data_processing(int sum, string* team, int*** arr, int games, int result, ifstream& file, int from, int to)
{
	int*** arr_v = new int** [sum];
	for (int i = 0; i < sum; i++)
	{
		arr_v[i] = new int* [10];
		create_dynamic(arr_v[i], 10, 2);
	}
	//char subline[100];
	for (int i = from; i < to; i++)
	{
		getline(file, team[i], ',');
		/*file >> subline;

		for (int j=0,f=0; j < games, f<strlen(subline) ; j++, f+=4)
		{
			arr[i][j][0] = int(subline[f]) - 48;
			arr[i][j][1] = int(subline[f+2])-48;

		}*/
		string line;
		getline(file, line);
		istringstream in(line);
		for (int j = 0; j < games; j++)
		{

			for (int l = 0; l < 4; l++) {
				if (in >> arr[i][j][l]) {

				}
				else {

					in.clear();
					in.ignore();
				}


				//cout << i << j << l << " = " << arr[i][j][l] << "   ";
				//cout << arr_v[i][j][l] << "   ";




			}
			cout << endl;
		}

	}
	for (int i = from; i < to; i++) {
		for (int j = 0; j < games; j++) {
			for (int l = 0, k = 0; l < 4, k < 2; l += 2, k++) {
				arr[i][j][k] = arr[i][j][l];
				cout << arr[i][j][k] << "   ";
			}
			cout << endl;
			
		}
	}
	file.close();

}

int Dir(int sum, int games, int competitors, string* teams, int ***arr, int * results)//обработка 
{
	int from = 0; int p;
	int to=0;
	setlocale(LC_ALL, "Russian");

	WIN32_FIND_DATAA findData;
	HANDLE hf;
	string name;
	hf = FindFirstFileA("Teams\\*.csv", &findData);

	if (hf == INVALID_HANDLE_VALUE)
	{
		cout << "Cannot find file" << endl;
		return -1;
	}
	do
	{
		name = findData.cFileName;
		ifstream file("Teams\\"+name);
		file >>p ;
		to += p;


		data_processing(sum,teams, arr, games, competitors, file, from, to);
		data_points(arr, games, competitors, results, from, to);
	
		from += to;
	} while (FindNextFileA(hf, &findData));
	

	FindClose(hf);
	

}

int team_numbers()//подсчет всех команд
{
	int num=0;
	int sum=0;
	string name;
	setlocale(LC_ALL, "Russian");

	WIN32_FIND_DATAA findData;
	HANDLE hf;
	hf = FindFirstFileA("Teams\\*.csv", &findData);

	if (hf == INVALID_HANDLE_VALUE)
	{
		cout << "Cannot find file" << endl;
		return -1;
	}
	int k = 0;
	do
	{
		name = findData.cFileName;
		ifstream file("Teams\\" + name);
		file >> num;
		sum+=num;
		file.close();

	} while (FindNextFileA(hf, &findData));


	FindClose(hf);
	return sum;
}

void shell_sort(int* results, int size)//сортировка
{
	for (int d = size / 2; d >= 1; d /= 2)
	{
		for (int i = d; i < size; i++)
		{
			int j = i;
			
			while (j >= d && results[j - d] <results[j])
			{
				swap(results[j], results[j - d]);
				j -= d;
			}
		}

	}
}

void input_data(string *teams, int sum, int * result)
{
	ofstream file("Result\\results.csv");
	for (int i = 0; i < sum; i++)
	{
		file << teams[i] << "," << result[i];
	}
	
}
