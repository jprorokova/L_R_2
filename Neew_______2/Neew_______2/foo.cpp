#include "foo.h"
#include <fstream>
#include<iostream>
#include<string>
#include <sstream> 
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

void processing_data(int*** arr, int games, int teams, int competitors, int* results)
{
	for (int i = 0; i < teams; i++)
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
void output_results(int*** arr, int games, int team, int competitors, int* results, string* teams) {
	for (int i = 0; i < team; i++)
	{
		cout << teams[i] << " : " << results[i] << endl;


	}
}

void input_to_file_data()
{

}

void output_data(string* team, int ***arr, int games, int results, int teams)
{
	for (int i = 0; i < teams; i++)
	{
		cout << team[i] << endl;
		for (int j = 0; j < games; j++)
		{
			cout << "game ¹ " << j+1<<endl;
			for (int k = 0; k < results; k++)
			{
				cout << arr[i][j][k]<<ends;
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}

void data_processing(string* team, int ***arr, int games, int result, int sum_of_teams, ifstream &file)
{
	char subline[100];
	for (int i = 0; i < sum_of_teams; i++)
	{
		getline(file, team[i], ',');
		file >> subline;

		for (int j=0,f=0; j < games, f<strlen(subline) ; j++, f+=4)
		{
			arr[i][j][0] = int(subline[f]) - 48;
			arr[i][j][1] = int(subline[f+2])-48;
			
		}
	}
	file.close();
}
