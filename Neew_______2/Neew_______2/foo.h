#pragma once
#include <fstream>
#include<iostream>
#include<string>
#include <sstream> 
#include <direct.h>
#include <io.h>
#include <windows.h>
#include <TlHelp32.h>
using namespace std;

void Dir();
void create_dynamic(int** arr, int games, int competitors);
void output_data(string* team, int*** arr, int games, int competitors, int teams);
void data_processing(string* str, int*** arr, int games, int competitors, int teams, ifstream& file);
void delete_array(string* teams);
void delete_array(int* result);
void delete_dynamic(int*** arr, int games, int teams);
void input_data();
void output_results(int*** arr, int games, int team, int competitors, int* results, string* teams);
void processing_data(int*** arr, int games, int teams, int competitors, int* results);


