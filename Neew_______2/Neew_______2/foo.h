#pragma once
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


int Dir(int sum, int games, int competitors, string* teams, int*** arr, int* results);
int team_numbers();
void create_dynamic(int** arr, int games, int competitors);
void data_processing(int sum, string* team, int*** arr, int games, int result, ifstream& file, int from, int to);
void delete_array(string* teams);
void delete_array(int* result);
void delete_dynamic(int*** arr, int games, int teams);
void shell_sort(int* results, int size);
void output_results(int*** arr, int games, int competitors, int* results, string* teams, int sum);
void data_points(int*** arr, int games, int competitors, int* results, int from, int to);
void input_data(string* teams, int sum, int* result);
