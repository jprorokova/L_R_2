#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include"foo.h"
#include<direct.h>
#include<windows.h>
using namespace std;


int main() {
	setlocale(0, "russian");

	Dir();


	ifstream file("data.csv");
	int sum=0;
	int games = 10;
	int competitors = 2;
	file >> sum;

	string* teams = new string[sum];
	int*** arr = new int** [sum];
	int* results = new int[sum]{};

	for (int i = 0; i < sum; i++)
	{
		arr[i] = new int* [10];
		create_dynamic(arr[i], 10, 2);
	}

	data_processing(teams, arr, games, competitors, sum, file);
	output_data(teams, arr,games , competitors, sum);
	processing_data(arr, games,sum, competitors, results);
	output_results(arr, games, sum, competitors,  results, teams);
	delete_dynamic(arr, games, sum);
	delete_array(teams);


}
