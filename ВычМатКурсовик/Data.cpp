#include "stdafx.h"
#include "Data.h"

vector<double> GetDoubleElement(string str)
{
	vector<double> row;
	int cpos = 0, pos = 0;
	string tmp;
	string::iterator striter = str.begin();
	while(striter != str.end())
	{
		cpos = str.find(" ", pos);
		tmp = str.substr(pos, cpos - pos);
		//добавте сюда проверку на / делайте double drob = atoi(tmp4.c_str())/atoi(tmpZ.c_str()) и вот вам блять дроби уебки!
		row.push_back(atof(tmp.c_str()));
		striter = str.begin();
		striter = striter + (cpos+1);
		pos = cpos + 1;
		if(cpos == -1) break;
	}
	return row;
}

vector<vector<double>> ReadFromFile(char *filename)
{
	ifstream matrix;
	vector<double> tm;
	vector<vector<double>> A;
	vector<double>::iterator iter = tm.begin();
	string str;
	matrix.open(filename);
	if(matrix.is_open())
	{
		while(!matrix.eof())
		{
			getline(matrix, str);
			tm = GetDoubleElement(str);
			A.push_back(tm);
		}
	}
	return A;
}

void show(vector <vector <double>> A)
{
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A.size(); j++)
        {
            cout <<" "<< A[i][j] << " ";
        }
        cout << endl;
    }
}

void show(vector<double>A)
{
	vector<double>::iterator iter = A.begin();
	while(iter != A.end())
	{
		cout << " " << *iter << "\n";
		iter++;
	}
	cout << endl;
}