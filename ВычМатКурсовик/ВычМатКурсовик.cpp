#include "stdafx.h"
#include <iostream>
#include "calcmd.h"
#include "Data.h"
#define MATRIX_SIZE 4
#define FILE_MATRIX "../matrix.txt"
using namespace std;

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