#include <vector>
#include <math.h>
using namespace std;

void LU(vector <vector <double>> A, vector <vector <double>> &L, 
        vector <vector <double>> &U);
void proisv(vector <vector <double>> A, vector <vector <double>> B, 
            vector <vector <double>> &R);
void QR(vector<vector <double>> A, vector<double>B);
void LU_slau(vector<vector<double>>L, vector<vector<double>>U, vector<double>B);
double determ(vector<vector<double>>matrix);