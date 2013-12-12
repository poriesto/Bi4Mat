#include "stdafx.h"
#include "calcmd.h"

void LU(vector <vector <double>> A, vector <vector <double>> &L, 
        vector <vector <double>> &U)
{
    U=A;

    for(int i = 0; i < U.size(); i++)
        for(int j = i; j < U.size(); j++)
            L[j][i]=U[j][i]/U[i][i];
    
    for(int k = 1; k < U.size(); k++)
    {
        for(int i = k-1; i < U.size(); i++)
            for(int j = i; j < U.size(); j++)
                L[j][i]=U[j][i]/U[i][i];

        for(int i = k; i < U.size(); i++)
            for(int j = k-1; j < U.size(); j++)
                U[i][j]=U[i][j]-L[i][k-1]*U[k-1][j];
    }

}

void proisv(vector <vector <double>> A, vector <vector <double>> B, 
            vector <vector <double>> &R)
{
    for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < A.size(); j++)
            for(int k = 0; k < A.size(); k++)
                R[i][j] += A[i][k] * B[k][j];
}

void QR(vector<vector<double>>A, vector<double> B)
{
	vector<vector<double>> c(A.size()), s(A.size());
	vector<double>x(A.size());
	for(int k = 0; k != A.size(); k++){
		for(int l = k+1; l != A.size(); l++){
			c[k][l] = A[k][k] / ( sqrt( pow(A[k][k], 2) + pow(A[l][k],2)));
			s[k][l] = A[l][k] / ( sqrt( pow(A[k][k], 2) + pow(A[l][k],2)));
			
			//a[][] * T[][]
			A[k][k] = A[k][k]*c[k][l] + A[l][k]*s[k][l];
			A[k][l] = A[k][l]*c[k][l] + A[l][l]*s[k][l];
			A[l][k] = -A[k][k]*s[k][l] + A[l][k]*c[k][l];
			A[l][l] = -A[k][l]*s[k][l] + A[l][l]*c[k][l];

			// Вектор свободных членов умножается на T[k][l]
			B[k] = B[k]*c[k][l] + B[l]*s[k][l];
			B[l] = -B[k]*s[k][l] + B[l]*c[k][l];
		}
	}
	double h;
	x[A.size()-1] = (B[A.size()-1]/A[A.size()-1][A.size()-1]);
	for(int l = (A.size()-1); l >= 1; l--)
	{
		h = B[l-1];
		for(int k = (l+1); k <= A.size(); k++){
			x[l-1] = h/A[l-1][l-1];
		}
	}
}
