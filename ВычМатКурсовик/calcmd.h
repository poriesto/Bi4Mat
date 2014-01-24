#include <vector>
#include <math.h>
using namespace std;

//Разложения матриц
void LU(vector <vector <double>> A, vector <vector <double>> &L, 
        vector <vector <double>> &U);
vector<vector<double>> L_LT_decomposition(vector< vector<double> > &A_matrix);
void QR(vector<vector<double>>A, vector<vector<double>>&Q, vector<vector<double>>&R);
//Действия над матрицами
vector<vector<double>>Summary(vector <vector <double>> A, vector <vector <double>> B);
vector<vector<double>> Multiplication(vector <vector <double>> A, vector <vector <double>> B);
vector<vector<double>>Multiplicaiton(vector<vector<double>>A, double B);
vector<vector<double>> Transpose_Matrix(vector< vector<double> > &matrix);
double Determinant(vector<vector<double>>matrix);
//решение СЛАУ
vector<double>Isolve(vector<vector<double>>A, vector<double>B);
