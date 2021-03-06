#include "stdafx.h"

int _tmain(){

	std::string FILE_MATRIX_A = "../matrixA.txt";
    std::string FILE_MATRIX_B = "../matrixB.txt";

	std::vector<std::vector<double> > A = ReadFromFile(FILE_MATRIX_A);
	std::vector<double>B = ReadFromFile(FILE_MATRIX_B, 0);
	std::vector<std::vector<double> >L(A.size()), U(A.size());

	LU(A,L,U);
    std::cout << "Matrix A" << std::endl;
	show(A);
    std::cout << "U matrix" << std::endl;
    show(U);
    std::cout << "L matrix" << std::endl;
    show(L);
    std::cout << "L*U matrix" << std::endl;
    show(Multiplication(L,U));

	std::cout << "B: " << std::endl;
	show(B);
	std::cout << "decision Ax = B" << std::endl;
	show(Isolve(A,B));
	std::cout << "decision Ly = B" << std::endl;
	show(Isolve(L,B));
	std::cout << "decision Ux = y" << std::endl;
	show(Isolve(U, Isolve(L,B)));

	system("pause");
    return 0;
}