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

	int sum = 0;
	int games = 10;
	int competitors = 2;
	sum = team_numbers();
	
	string* teams = new string[sum];
	int*** arr = new int** [sum];
	int* results = new int[sum]{};

	for (int i = 0; i < sum; i++)
	{
		arr[i] = new int* [10];
		create_dynamic(arr[i], 10, 2);
	}

	Dir(sum, games, competitors, teams, arr, results);
	shell_sort(results, sum);
	output_results(arr, games, competitors, results, teams, sum);
	input_data(teams, sum, results);
	delete_dynamic(arr, games, sum);
	delete_array(teams);


}
