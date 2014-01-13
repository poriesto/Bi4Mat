#include "stdafx.h"
#include "calcmd.h"
#include "Data.h"
#define FILE_MATRIX_A "../matrixA.txt"
#define FILE_MATRIX_A1 "../matrixA1.txt"
#define FILE_MATRIX_B "../matrixB.txt"
#define FILE_MATRIX_B1 "../matrixB1.txt"

int _tmain(int argc, _TCHAR* argv[]){

	vector<vector<double>> A = ReadFromFile(FILE_MATRIX_A), A1 = ReadFromFile(FILE_MATRIX_A1);
	vector<double>B = ReadFromFile(FILE_MATRIX_B, 0), B1 = ReadFromFile(FILE_MATRIX_B1, 0), x, y;
	vector<vector<double>>L(A.size()), U(A.size()), R;
	
	LU(A,L,U);
    cout << "Matrix A" << endl;
	show(A);
    cout << "U matrix" << endl;
    show(U);
    cout << "L matrix" << endl;
    show(L);
	R = Multiplication(L,U);
    cout << "L*U matrix" << endl;
    show(R);

	cout << "B: " << endl;
	show(B);
	cout << "decision Ax = B" << endl;
	show(Isolve(A,B));
	cout << "decision Ly = B" << endl;
	y = Isolve(L,B);
	show(y);
	cout << "decision Ux = y" << endl;
	x = Isolve(U, y);
	show(x);

	system("pause");
    return 0;
}