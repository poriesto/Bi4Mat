#include "Data.h"
#include "calcmd.h"

const std::string FILE_MATRIX_A = {"../txt/matrixA.txt"};
const std::string FILE_MATRIX_B = {"../txt/matrixB.txt"};

int main(){
	
	std::vector<std::vector<double> > A(ReadFromFile(FILE_MATRIX_A)), E(CreateIdentityMatrix((int)A.size())), LUmatrix(LU(A));
    std::vector<std::vector<double> > L(getL_matrix(LUmatrix)), U(getU_matrix(LUmatrix));
    std::vector<double > B(ReadFromFile(FILE_MATRIX_B, 0));
    
    std::cout << "Matrix A" << std::endl;
	show(A);
	std::cout << "LU decomp matrix:" << std::endl;
    show(LUmatrix);
    std::cout << std::endl << "L matrix" << std::endl;
    show(L);
    std::cout << std::endl << "U matrix" << std::endl;
    show(U);
    std::cout << std::endl << "L*U matrix" << std::endl;
    show(Multiplication(L,U));
    
    //Calculate Ax=B or LUx = B, Ly = B, Ux = y
	std::cout << std::endl << "B: " << std::endl;
	show(B);
	std::cout << "decision Ax = B" << std::endl;
	show(Isolve(A,B));
	std::cout << "decision Ly = B" << std::endl;
	show(Isolve(L,B));
	std::cout << "decision Ux = y" << std::endl;
	show(Isolve(U, Isolve(L,B)));
    
    // AX = I, LUX = I, LY = I, UX = Y
    std::cout << "Find reverse matrix for matrix A" << std::endl << std::endl;
    std::cout << "Identity matrix:" << std::endl;
    show(E);
    std::cout << std::endl << "rev matrix LU:" << std::endl;
    show(InreverseMatrix(L,U,E));
    std::cout << std::endl << "rev matrix A:" << std::endl;
    show(InreverseMatrix(A,E));
    
    return 0;
}