#include "Data.h"
#include "calcmd.h"

int main(){
    
    std::string FILE_MATRIX_A = {"../matrixA.txt"};
    std::string FILE_MATRIX_B = {"../matrixB.txt"};
    
	std::vector<std::vector<double> > A(ReadFromFile(FILE_MATRIX_A));
	std::vector<double > B(ReadFromFile(FILE_MATRIX_B, 0));
	std::vector<std::vector<double> >L(A.size()), U(A.size());

	LU(A,L,U);
    std::cout << "Matrix A" << std::endl;
	show(A);
    std::cout << std::endl << "U matrix" << std::endl;
    show(U);
    std::cout << std::endl << "L matrix" << std::endl;
    show(L);
    std::cout << std::endl << "L*U matrix" << std::endl;
    show(Multiplication(L,U));

	std::cout << "B: " << std::endl;
	show(B);
	std::cout << "decision Ax = B" << std::endl;
	show(Isolve(A,B));
	std::cout << "decision Ly = B" << std::endl;
	show(Isolve(L,B));
	std::cout << "decision Ux = y" << std::endl;
	show(Isolve(U, Isolve(L,B)));
    
    std::cout << "Find reverse matrix for matrix A" << std::endl << std::endl;
    // AX = I, LUX = I, LY = I, UX = Y
    std::cout << "Identity matrix:" << std::endl;
    show(CreateIdentityMatrix((int)A.size()));
    std::cout << std::endl << "rev matrix LU:" << std::endl;
    show(InreverseMatrix(L,U,CreateIdentityMatrix((int)A.size())));
    std::cout << std::endl << "rev matrix A:" << std::endl;
    show(InreverseMatrix(Multiplication(L,U),CreateIdentityMatrix((int)A.size())));
    
    return 0;
}