#include "stdafx.h"
#include "calcmd.h"
#include "Data.h"
#define MATRIX_SIZE 4
#define FILE_MATRIX_A "../matrixA.txt"
#define FILE_MATRIX_B "../matrixB.txt"

int main()
{
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
<<<<<<< HEAD
	/*cout << "Matrix B:" << endl;
	show(B);*/
=======
	//cout << "Matrix B:" << endl;
	//show(B);
>>>>>>> 09a43b6101728c62738222959cfbe268598cfc41
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
	system("pause");
    return 0;
}