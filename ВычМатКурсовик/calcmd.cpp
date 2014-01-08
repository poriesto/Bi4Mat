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

void QR(vector<vector<double>>A/*, vector<double> B*/)
{
	vector<vector<double>> c = A; 
	vector<vector<double>> s = A;
	//vector<double>x(A.size());
	for(int k = 0; k < A.size(); k++){
		for(int l = k+1; l < A.size(); l++){
			c[k][l] = A[k][k] / ( sqrt( pow(A[k][k], 2) + pow(A[l][k],2)));
			s[k][l] = A[l][k] / ( sqrt( pow(A[k][k], 2) + pow(A[l][k],2)));
			cout << "c[" << k << "][" << l << "] = " << "A[" << k << "][" << k << "] /  A[" << k << "][" << k << "] + A[" << l << "][" << k << "]" << endl;  
			cout << "s[" << k << "][" << l << "] = " << "A[" << l << "][" << k << "] /  A[" << k << "][" << k << "] + A[" << l << "][" << k << "]" << endl;
			//a[][] * T[][]
			A[k][k] = A[k][k]*c[k][l] + A[l][k]*s[k][l];
			A[k][l] = A[k][l]*c[k][l] + A[l][l]*s[k][l];
			A[l][k] = -A[k][k]*s[k][l] + A[l][k]*c[k][l];
			A[l][l] = -A[k][l]*s[k][l] + A[l][l]*c[k][l];
			cout << "A[" << k << "][" << k << "] = " << "A[" << k << "][" << k << "] * c[" << k << "][" << l << "] + A[" << l << "][" << k << "] * s[" << k << "][" << l << "]" << endl; 
			cout << "A[" << k << "][" << l << "] = " << "A[" << k << "][" << l << "] * c[" << k << "][" << l << "] + A[" << l << "][" << l << "] * s[" << k << "][" << l << "]" << endl; 
			cout << "A[" << l << "][" << k << "] = " << "-A[" << k << "][" << k << "] * s[" << k << "][" << l << "] + A[" << l << "][" << k << "] * c[" << k << "][" << l << "]" << endl; 
			cout << "A[" << l << "][" << l << "] = " << "-A[" << k << "][" << l << "] * s[" << k << "][" << l << "] + A[" << l << "][" << l << "] * c[" << k << "][" << l << "]" << endl; 
			/*// Вектор свободных членов умножается на T[k][l]
			B[k] = B[k]*c[k][l] + B[l]*s[k][l];
			B[l] = -B[k]*s[k][l] + B[l]*c[k][l];*/
		}
	}/*
	double h;
	x[A.size()-1] = (B[A.size()-1]/A[A.size()-1][A.size()-1]);
	for(int l = (A.size()-1); l >= 1; l--)
	{
		h = B[l-1];
		for(int k = (l+1); k <= A.size(); k++){
			x[l-1] = h/A[l-1][l-1];
		}
	}*/
}

void LU_slau(vector<vector<double>>L, vector<vector<double>>U, vector<double>B){

	vector<double>x, y;
	vector<vector<double>> Ly = L, Ux = U;
	
	for(int i = 0; i < L.size(); i++){
		for(int j = 0; j < L.size(); j++){
			Ly[j][i] = B[j];
		}
		x.push_back(determ(Ly)/determ(L));
		Ly = L;
	}
	for(int i = 0; i < L.size(); i++){
		for(int j = 0; j < L.size(); j++){
			Ux[j][i] = x[j];
		}
		y.push_back(determ(Ux)/determ(U));
		Ux = U;
	}

	cout << "decision Ly = B" << endl;
	show(x);
	cout << "decision Ux = y" << endl;
	show(y);
}

double determ(vector<vector<double>>a){
	int p=0, i, j, t, k;
	double kst = 0;
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