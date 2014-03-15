#include <vector>
#include <fstream>
#include <string>
#include <iostream>

std::vector<double> GetDoubleRow(std::string str);
double GetDoubleElement(std::string str);
std::vector<std::vector<double> > ReadFromFile(const std::string &filename);
std::vector<double>ReadFromFile(const std::string &filename, int size);
void show(std::vector<std::vector <double> > A);
void show(std::vector<double> A);
