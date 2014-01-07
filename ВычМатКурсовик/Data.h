#include "stdafx.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

vector<double> GetDoubleRow(string str);
double GetDoubleElement(string str);
vector<vector<double>> ReadFromFile(char *filename);
vector<double>ReadFromFile(char *filename, int size);
void show(vector <vector <double>> A);
void show(vector <double> A);