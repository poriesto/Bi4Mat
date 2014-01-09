#include "stdafx.h"
#include "calcmd.h"
#include "Data.h"
#define MATRIX_SIZE 4
#define FILE_MATRIX_A "../matrixA.txt"
#define FILE_MATRIX_A1 "../matrixA1.txt"
#define FILE_MATRIX_B "../matrixB.txt"
#define FILE_MATRIX_B1 "../matrixB1.txt"

int main(){
	vector<vector<double>> A = ReadFromFile(FILE_MATRIX_A), A1 = ReadFromFile(FILE_MATRIX_A1);
	vector<double>B = ReadFromFile(FILE_MATRIX_B, 0), x, y, B1 = ReadFromFile(FILE_MATRIX_B1, 0);
	vector<vector<double>>L(A.size()), U(A.size()), R(A.size());

	for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A.size(); j++){
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
	show(Isolve(A,B));

	cout << "decision Ly = B" << endl;
	y = Isolve(L,B);
	show(y);

	cout << "decision Ux = y" << endl;
	x = Isolve(U, y);
	show(x);
	cout << "A1:\n";
	show(A1);
	cout << "A=QR" << endl;
	QR(A1, B1);
	//show(A1);
	system("pause");
    return 0;
}




