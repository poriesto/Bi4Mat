#include "stdafx.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

vector<double> GetDoubleElement(string str);
vector<vector<double>> ReadFromFile(char *filename);
void show(vector <vector <double>> A);
void show(vector <double> A);
void Audio1();