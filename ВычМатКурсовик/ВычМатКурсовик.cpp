//#include "stdafx.h"
#include "calcmd.h"
#include "Data.h"
#define FILE_MATRIX_A "../matrixA.txt"
#define FILE_MATRIX_A1 "../matrixA1.txt"
#define FILE_MATRIX_B "../matrixB.txt"
#define FILE_MATRIX_B1 "../matrixB1.txt"

int _tmain(){

	std::vector<std::vector<double> > A = ReadFromFile(FILE_MATRIX_A), A1 = ReadFromFile(FILE_MATRIX_A1);
	std::vector<double>B = ReadFromFile(FILE_MATRIX_B, 0), B1 = ReadFromFile(FILE_MATRIX_B1, 0), x, y;
	std::vector<std::vector<double> >L(A.size()), U(A.size()), R;
	
	LU(A,L,U);
    std::cout << "Matrix A" << std::endl;
	show(A);
    std::cout << "U matrix" << std::endl;
    show(U);
    std::cout << "L matrix" << std::endl;
    show(L);
	R = Multiplication(L,U);
    std::cout << "L*U matrix" << std::endl;
    show(R);

	std::cout << "B: " << std::endl;
	show(B);
	std::cout << "decision Ax = B" << std::endl;
	show(Isolve(A,B));
	std::cout << "decision Ly = B" << std::endl;
	y = Isolve(L,B);
	show(y);
	std::cout << "decision Ux = y" << std::endl;
	x = Isolve(U, y);
	show(x);
	std::cout << "Transpouse matrix X: " << std::endl;
	show(Transpose_Matrix(R));
	//system("pause");
    return 0;
}