#include "stdafx.h"
#include "calcmd.h"
#include "data.h"

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