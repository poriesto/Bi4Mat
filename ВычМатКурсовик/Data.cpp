#include "stdafx.h"
#include "Data.h"

vector<double> GetDoubleElement(string str)
{
	vector<double> row;
	int cpos = 0, pos = 0;
	string tmp;
	string::iterator striter = str.begin();
	while(striter != str.end() - 1)
	{
		cpos = str.find(" ", pos);
		tmp = str.substr(pos, cpos - pos);
		row.push_back(atof(tmp.c_str()));
		striter = str.begin();
		striter = striter + (cpos+1);
		pos = cpos + 1;
		if(cpos == -1) break;
	}
	vector<double>::iterator iter = row.begin();
	return row;
}

vector<vector<double>> ReadFromFile(char *filename)
{
	ifstream matrix;
	double tm;
	vector<vector<double>> A;
	string str;
	int i = 0;
	matrix.open(filename);
	if(matrix.is_open())
	{
		while(!matrix.eof())
		{
			getline(matrix, str);
			A.push_back(GetDoubleElement(str));
		}
	}
	return A;
}