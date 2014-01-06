#include "stdafx.h"
#include "calcmd.h"
#include "data.h"
#include <iostream>
void LU(vector <vector <double>> A, vector <vector <double>> &L, 
        vector <vector <double>> &U)
{
    U=A;

    for(int i = 0; i < U.size(); i++){
        for(int j = i; j < U.size(); j++){
			L[j][i]=A[j][i]/U[i][i];
		}
	}
    for(int k = 1; k < U.size(); k++)
    {
        for(int i = k-1; i < U.size(); i++){
            for(int j = i; j < U.size(); j++){
				L[j][i]=U[j][i]/U[i][i];
			}}
        for(int i = k; i < U.size(); i++){
            for(int j = k-1; j < U.size(); j++){
                U[i][j]=U[i][j]-L[i][k-1]*U[k-1][j];
			}
		}
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

vector<double> Nev(vector<vector<double>>initial_matrix, vector<vector<double>>calculated_matrix)
{
	vector<double>nev;
	double tmp;
	for(int i = 0; i != initial_matrix.size(); i++){
		for(int j = 0; j != initial_matrix.size(); j++){
			tmp = calculated_matrix[i][j] - initial_matrix[i][j];
			nev.push_back(tmp);
		}
	}
	return nev;
}

vector<vector<double>>cholesky(vector<vector<double>>A){
	vector<vector<double>>L(A.size());
	for(int i = 0; i < A.size(); i++)
		{
		 for(int j = 0; j < A.size(); j++)
        {
			L[i].push_back(0);
       }
    }
	for(int i = 0; i < A.size(); i++){
		cout << A[i][i] << " ";
		for(int k = 0; k < i -1; k++) L[i][i] = A[i][i] - L[i][k]*L[i][k];
		cout << L[i][i] << " ";
		L[i][i] = sqrt(L[i][i]);
		for(int j = i + 1; j < A.size(); j++){
			for(int k = 0; k < i -1; k++) L[j][i] = A[j][i] - L[i][k]*L[j][k];
			L[j][i] = L[j][i] / L[i][i];
		}
	}
	return L;
}

void LU_slau(vector<vector<double>>L, vector<vector<double>>U, vector<double>B){
	double dtL1, dtL2, dtL3, dtL4, dtL;
	dtL = determ(L);
	vector<double>x, y;
	vector<vector<double>>Ly1 = L, Ly2 = L, Ly3 = L, Ly0 = L;
	vector<vector<double>>Ux1 = U, Ux2 = U, Ux3 = U, Ux0 = U;
	for(int i = 0; i < Ly1.size(); i++){
		Ly0[i][0] = B[i];
	}
	for(int i = 0; i < Ly1.size(); i++){
		Ly1[i][1] = B[i];
	}
	for(int i = 0; i < Ly2.size(); i++){
		Ly2[i][2] = B[i];
	}
	for(int i = 0; i < Ly3.size(); i++){
		Ly3[i][3] = B[i];
	}

	for(int i = 0; i < Ux1.size(); i++){
		Ux0[i][0] = B[i];
	}
	for(int i = 0; i < Ux1.size(); i++){
		Ux1[i][1] = B[i];
	}
	for(int i = 0; i < Ux2.size(); i++){
		Ux2[i][2] = B[i];
	}
	for(int i = 0; i < Ux3.size(); i++){
		Ux3[i][3] = B[i];
	}
	x.push_back(determ(Ly0)/dtL);
	x.push_back(determ(Ly1)/dtL);
	x.push_back(determ(Ly2)/dtL);
	x.push_back(determ(Ly3)/dtL);
	y.push_back(determ(Ux0)/determ(U));
	y.push_back(determ(Ux1)/determ(U));
	y.push_back(determ(Ux2)/determ(U));
	y.push_back(determ(Ux3)/determ(U));
	cout << "Slau:" << endl;
	vector<double>::iterator iter = x.begin();
	cout << "X: " << endl;
	while(iter != x.end()){
		cout << *iter << endl;
		iter++;
	}
	vector<double>::iterator iter1 = y.begin();
	cout << "Y: " << endl;
	while(iter != y.end()){
		cout << *iter1 << endl;
		iter1++;
	}
}

double determ(vector<vector<double>>a){
	int p=0, i, j, t, k;
	double kst;
	int n = a.size();
	for (i=0; i<n-1; i++){
		t=1;
	while(a[i][i]==0){
		for(j=0; j<n; j++){
			a[i][j]=kst;
			a[i][j]=a[i+t][j];
			a[i+t][j]=kst;
		}
		p++;
		t++;
	}
 
	for (k=i+1; k<n; k++){
		kst=a[k][i]/a[i][i];
		for(j=0; j<n; j++)
			a[k][j]-=a[i][j]*kst;
		}
	}
 
	kst=pow(-1,p);
	for(i=0; i<n; i++) kst*=a[i][i];
	return kst;
}