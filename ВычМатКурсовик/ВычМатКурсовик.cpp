#include "stdafx.h"
#include "calcmd.h"
#include "Data.h"
#define MATRIX_SIZE 4
#define FILE_MATRIX_A "../matrixA.txt"
#define FILE_MATRIX_B "../matrixB.txt"

int main()
{
	vector<vector<double>> A, B, L(MATRIX_SIZE), U(MATRIX_SIZE), R(MATRIX_SIZE), ch(MATRIX_SIZE);
	vector<double>New;
	double dt;
	A = ReadFromFile(FILE_MATRIX_A);
	B = ReadFromFile(FILE_MATRIX_B);
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
	/*New = Nev(A, R);
	cout << "Nevjazka:" << endl; 
	show(New);*/
	New.push_back(79);
	New.push_back(76);
	New.push_back(-141);
	New.push_back(23);
	cout << "B: " << endl;
	show(New);
	cout << "decision Ax = B" << endl;
	LU_slau(L, U, New);
	system("pause");
    return 0;
}




