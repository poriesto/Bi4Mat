#include <vector>
#include <math.h>
using namespace std;

void LU(vector <vector <double>> A, vector <vector <double>> &L, 
        vector <vector <double>> &U);
void proisv(vector <vector <double>> A, vector <vector <double>> B, 
            vector <vector <double>> &R);
void QR(vector<vector <double>> A, vector<double>B);
vector<double> Nev(vector<vector<double>>initial_matrix, vector<vector<double>>calculated_matrix);