#include "stdafx.h"
#include "calcmd.h"
#include "Data.h"
#define MATRIX_SIZE 4
#define FILE_MATRIX_A "../matrixA.txt"
#define FILE_MATRIX_A1 "../matrixA1.txt"
#define FILE_MATRIX_B "../matrixB.txt"

int main()
{
	vector<vector<double>> A, A1, L(MATRIX_SIZE), U(MATRIX_SIZE), R(MATRIX_SIZE);
	vector<double>B;
	double dt;
	A = ReadFromFile(FILE_MATRIX_A);
	A1 = ReadFromFile(FILE_MATRIX_A1);
	B = ReadFromFile(FILE_MATRIX_B, 1);
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
    cout << "U matrix" << endl;
    show(U);
    cout << "L matrix" << endl;
    show(L);
    proisv(L,U,R);
    cout << "L*U matrix" << endl;
    show(R);
	cout << "B: " << endl;
	show(B);
	cout << "decision Ax = B" << endl;
	LU_slau(L, U, B);
	QR(A1);
	system("pause");
    return 0;
}




