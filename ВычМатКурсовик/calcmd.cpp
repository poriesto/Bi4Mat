#include "stdafx.h"
#include "calcmd.h"
#include "data.h"
#include <iostream>
void LU(vector <vector <double>> A, vector <vector <double>> &L, 
        vector <vector <double>> &U){
    U=A;

    for(int i = 0; i < U.size(); i++){
        for(int j = i; j < U.size(); j++){
			L[j][i]=A[j][i]/U[i][i];
		}
	}
    for(int k = 1; k < U.size(); k++){
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
            vector <vector <double>> &R){
    for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < A.size(); j++)
            for(int k = 0; k < A.size(); k++)
                R[i][j] += A[i][k] * B[k][j];
}

void QR(vector<vector<double>>A, vector<double> B){
	vector<vector<double>>R = A;
	double akk, alk, akl, all, c ,s;
	for(int k = 0; k < A.size()-1; k++){
		for(int l = k+1; l < A.size(); l++){
			c = A[k][k] / ( sqrt( pow(A[k][k], 2) + pow(A[l][k],2)));
			s = A[l][k] / ( sqrt( pow(A[k][k], 2) + pow(A[l][k],2)));
			//cout << "c = " << "A[" << k << "][" << k << "] /  A[" << k << "][" << k << "] + A[" << l << "][" << k << "]" << endl << endl << endl << endl;  
			//cout << "s = " << "A[" << l << "][" << k << "] /  A[" << k << "][" << k << "] + A[" << l << "][" << k << "]" << endl << endl << endl << endl;
			//a[][] * T[][]
			akk=R[k][k];  alk=R[l][k];  akl=R[k][l];  all=R[l][l];
			R[k][k] =  akk*c + alk*s;
		    R[k][l] =  akl*c + all*s;
		    R[l][k] = -akk*s + alk*c;
		    R[l][l] = -akl*s + all*c;
		    cout << "A[" << k << "][" << k << "] = " << "A[" << k << "][" << k << "] * c[" << k << "][" << l << "] + A[" << l << "][" << k << "] * s[" << k << "][" << l << "] = " <<   akk <<" * " << c << " + " << alk <<" * " << s << " = " << akk*c + alk*s <<endl; 
			cout << "A[" << k << "][" << l << "] = " << "A[" << k << "][" << l << "] * c[" << k << "][" << l << "] + A[" << l << "][" << l << "] * s[" << k << "][" << l << "] = " << akl*c + all*s << endl; 
			cout << "A[" << l << "][" << k << "] = " << "-A[" << k << "][" << k << "] * s[" << k << "][" << l << "] + A[" << l << "][" << k << "] * c[" << k << "][" << l << "] = " << -akk <<" * " << c << " + " << alk <<" * " << s << " = " << -akk*s + alk*c << endl; 
			cout << "A[" << l << "][" << l << "] = " << "-A[" << k << "][" << l << "] * s[" << k << "][" << l << "] + A[" << l << "][" << l << "] * c[" << k << "][" << l << "]" << -akl*s + all*c << endl; 
			// Вектор свободных членов умножается на T[k][l]
			B[k] = B[k]*c + B[l]*s;
			B[l] = -B[k]*s + B[l]*c;
		}
	}
	show(R);
	/*
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

vector<double> Isolve(vector<vector<double>>A, vector<double>B){
	vector<double>x;
	vector<vector<double>> Ax = A;
	if(determ(A) != 0){
		for(int i = 0; i < A.size(); i++){
			for(int j = 0; j < A.size(); j++){
				Ax[j][i] = B[j];
			}
			x.push_back(determ(Ax)/determ(A));
			Ax = A;
		}
		return x;
	}
	else{
		cout << "Determ initial matrix = 0\n";
		for(int i = 0; i < A.size(); i++) x.push_back(0);
		return x;
	}
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