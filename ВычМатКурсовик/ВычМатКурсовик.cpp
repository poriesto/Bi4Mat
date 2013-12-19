#pragma comment(lib, "winmm.lib")
#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "calcmd.h"
#include "Data.h"
#define MATRIX_SIZE 4
#define FILE_MATRIX_A "../matrixA.txt"
#define FILE_MATRIX_B "../matrixB.txt"
using namespace std;

int main()
{
	Audio1();
	cout << "Vvedite pazmepnost matrix:" << endl;
    vector<vector<double>> A, B, L(MATRIX_SIZE), U(MATRIX_SIZE), R(MATRIX_SIZE);
	vector<double>New;
	A = ReadFromFile(FILE_MATRIX_A);
	//B = ReadFromFile(FILE_MATRIX_B);
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
    cout << "Matrix A" << endl;
	show(A);
	/*cout << "Matrix B:" << endl;
	show(B);*//*
    cout << "U matrix" << endl;
    show(U);*/
    cout << "L matrix" << endl;
    show(L);/*
    proisv(L,U,R);
    cout << "L*U matrix" << endl;
<<<<<<< HEAD
    show(R);*/
=======
    show(R);
	New = Nev(A, R);
	cout << "Nevjazka:" << endl; 
	show(New);
>>>>>>> 33ca11a1b3617ed3bdcbba7c97b0be6b1d6c0b54
	system("pause");
    return 0;
}