#include <vector>
#include <math.h>

//Разложения матриц
void LU(std::vector<std::vector<double>> A, std::vector<std::vector<double>>&L, 
        std::vector<std::vector<double>>&U);
std::vector<std::vector<double>> L_LT_decomposition(std::vector<std::vector<double>> &A_matrix);
void QR(std::vector<std::vector<double>>A, std::vector<std::vector<double>>&Q, std::vector<std::vector<double>>&R);
//Действия над матрицами
std::vector<std::vector<double>>Summary(std::vector<std::vector<double>> A, std::vector<std::vector <double>> B);
std::vector<std::vector<double>> Multiplication(std::vector <std::vector <double>> A, std::vector<std::vector<double>> B);
std::vector<std::vector<double>>Multiplicaiton(std::vector<std::vector<double>>A, double B);
std::vector<std::vector<double>> Transpose_Matrix(std::vector<std::vector<double>> &matrix);
double Determinant(std::vector<std::vector<double>>matrix);
//решение СЛАУ
std::vector<double>Isolve(std::vector<std::vector<double>>A, std::vector<double>B);
