#pragma once
#include <fstream>
#include<iostream>
#include<string>
using namespace std;


void create_dynamic(int** arr, int games, int competitors);
void output_data(string* team, int*** arr, int games, int competitors, int teams);
void data_processing(string* str, int*** arr, int games, int competitors, int teams, ifstream& file);
void delete_array(string* teams);
void delete_array(int* result);
void delete_dynamic(int*** arr, int games, int teams);
void input_data();



