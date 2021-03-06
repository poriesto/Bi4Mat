#include <vector>
#include <math.h>

//Разложения матриц
std::vector<std::vector<double> > LU(std::vector<std::vector<double> > A);
std::vector<std::vector<double> > L_LT_decomposition(std::vector<std::vector<double> > &A_matrix);
void QR(std::vector<std::vector<double> >A, std::vector<std::vector<double> >&Q, 
        std::vector<std::vector<double> >&R);
std::vector<std::vector<double> > getL_matrix(std::vector<std::vector<double> > LU);
std::vector<std::vector<double> > getU_matrix(std::vector<std::vector<double> > LU);
//Действия над матрицами
std::vector<std::vector<double> > Summary(std::vector<std::vector<double> > A, std::vector<std::vector <double> > B);
std::vector<std::vector<double> > Multiplication(std::vector <std::vector <double> > A, std::vector<std::vector<double> > B);
std::vector<std::vector<double> > Multiplicaiton(std::vector<std::vector<double> >A, double B);
std::vector<std::vector<double> > Transpose_Matrix(std::vector<std::vector<double> > &matrix);
double Determinant(std::vector<std::vector<double> >matrix);
std::vector<std::vector<double> > CreateIdentityMatrix(int size);
//решение СЛАУ
std::vector<double> Isolve(std::vector<std::vector<double> >A, std::vector<double> B);
std::vector<std::vector<double> > InreverseMatrix(std::vector<std::vector<double> >A, std::vector<std::vector<double> >E);
std::vector<std::vector<double> > InreverseMatrix(std::vector<std::vector<double> >L, std::vector<std::vector<double> >U, 
        std::vector<std::vector<double> >E);
