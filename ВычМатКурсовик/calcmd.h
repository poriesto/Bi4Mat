#include <vector>
#include <math.h>
using namespace std;

void LU(vector <vector <double>> A, vector <vector <double>> &L, 
        vector <vector <double>> &U);
vector<vector<double>> Multiplication(vector <vector <double>> A, vector <vector <double>> B);
double Determinant(vector<vector<double>>matrix);
vector<double>Isolve(vector<vector<double>>A, vector<double>B);