#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#define MATRIX_SIZE 4
#define FILE_MATRIX "../matrix.txt"
using namespace std;

void LU(vector <vector <double>> A, vector <vector <double>> &L, 
        vector <vector <double>> &U)
{
    U=A;

    for(int i = 0; i < U.size(); i++)
        for(int j = i; j < U.size(); j++)
            L[j][i]=U[j][i]/U[i][i];
    
    for(int k = 1; k < U.size(); k++)
    {
        for(int i = k-1; i < U.size(); i++)
            for(int j = i; j < U.size(); j++)
                L[j][i]=U[j][i]/U[i][i];

        for(int i = k; i < U.size(); i++)
            for(int j = k-1; j < U.size(); j++)
                U[i][j]=U[i][j]-L[i][k-1]*U[k-1][j];
    }

}

void proisv(vector <vector <double>> A, vector <vector <double>> B, 
            vector <vector <double>> &R)
{
    for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < A.size(); j++)
            for(int k = 0; k < A.size(); k++)
                R[i][j] += A[i][k] * B[k][j];
}

void show(vector <vector <double>> A)
{
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A.size(); j++)
        {
            cout <<"\t"<< A[i][j] << "\t";
        }
        cout << endl;
    }
}

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

int main()
{
	cout << "Vvedite pazmepnost matrix:" << endl;
    vector<vector<double>> A, L(MATRIX_SIZE), U(MATRIX_SIZE), R(MATRIX_SIZE);
	A = ReadFromFile(FILE_MATRIX);
	for(int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_SIZE; j++)
        {
			L[i].push_back(0);
            U[i].push_back(0);
            R[i].push_back(0);
       }
    }
    LU(A,L,U);
    cout << "Fisrt matrix" << endl;
	show(A);
    cout << "U matrix" << endl;
    show(U);
    cout << "L matrix" << endl;
    show(L);
    proisv(L,U,R);
    cout << "L*U matrix" << endl;
    show(R);
	system("pause");
    return 0;
}