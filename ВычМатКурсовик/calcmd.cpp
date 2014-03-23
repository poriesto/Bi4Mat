#include "calcmd.h"

std::vector<std::vector<double> > LU(std::vector<std::vector<double> > A){
    std::vector<std::vector<double> >U(A), L((int)A.size()), LU((int)A.size());
    
	for(int i = 0; i < (int)A.size(); i++){
        for(int j = 0; j < (int)A.size(); j++){
			L[i].push_back(0);
            U[i].push_back(0);
            LU[i].push_back(0);
       }
    }
    for(int i = 0; i < (int)U.size(); i++){
        for(int j = i; j < (int)U.size(); j++){
			L[j][i]=A[j][i]/U[i][i];
		}
	}
    for(int k = 1; k < (int)U.size(); k++){
        for(int i = k-1; i < (int)U.size(); i++){
            for(int j = i; j < (int)U.size(); j++){
				L[j][i]=U[j][i]/U[i][i];
			}}
        for(int i = k; i < (int)U.size(); i++){
            for(int j = k-1; j < (int)U.size(); j++){
                U[i][j]=U[i][j]-L[i][k-1]*U[k-1][j];
			}
		}
    }
    for(int i = 0; i < (int)A.size(); i++){
        for(int j = 0; j < (int)A.size(); j++){
            if(i > j){
                LU[i][j] = L[i][j];
            }
            else{
                LU[i][j] = U[i][j];
            }
        }
        LU[i][i] = U[i][i];
    }
    std::vector<std::vector<double> >(L).swap(L);
    std::vector<std::vector<double> >(U).swap(U);
    return LU;
}

std::vector<std::vector<double> > getL_matrix(std::vector<std::vector<double> > LU){
    std::vector<std::vector<double> >L(LU);
    
    for(int i = 0; i < (int)LU.size(); i++){
        for(int j = 0; j < (int)LU.size(); j++){
            if(i == j){
                L[i][j] = 1;
            }
            else if(i < j) L[i][j] = 0;
        }
    }
    return L;
}

std::vector<std::vector<double> > getU_matrix(std::vector<std::vector<double> > LU){
    std::vector<std::vector<double> >U(LU);
    
    for(int i = 0; i < (int)LU.size(); i++){
        for(int j = 0; j < (int)LU.size(); j++){
            if(i == j){
                U[i][j] = LU[i][j];
            }
            else if(i > j){
                U[i][j] = 0;
            }
        }
    }
    return U;
}

std::vector<std::vector<double> > Multiplication(std::vector<std::vector<double> >A, std::vector<std::vector <double> > B){
    std::vector<std::vector<double> >C(A.size());
		
    for(int i = 0; i < (int)A.size(); i++){
        for(int j = 0; j < (int)A.size(); j++){
            C[i].push_back(0);
       }
    }
    for(int i = 0; i < (int)A.size(); i++)
        for(int j = 0; j < (int)A.size(); j++)
            for(int k = 0; k < (int)A.size(); k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

std::vector<std::vector<double> > Multiplicaiton(std::vector<std::vector<double> >A, double B){
    std::vector<std::vector<double> >C(A.size());
    
    for(int i = 0; i < (int)C.size(); i++){
        for(int j = 0; j < (int)C.size(); j++){
			C[i].push_back(0);
        }
    }
    for(int i = 0; i < (int)A.size(); i++){
        for(int j = 0; j < (int)A.size(); j++){
            C[i][j] = A[i][j]*B; 
        }
    }
    return C;
}

std::vector<std::vector<double> > Summary(std::vector<std::vector<double> >A, std::vector<std::vector<double> > B){
    std::vector<std::vector<double> >C(A.size());
    
    for(int i = 0; i < (int)C.size(); i++){
        for(int j = 0; j < (int)C.size(); j++){
            C[i].push_back(0);
        }
    }
    for(int i = 0; i < (int)C.size(); i++){
        for(int j = 0; j < (int)C.size(); j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

std::vector<double > Isolve(std::vector<std::vector<double> >A, std::vector<double>B){
	std::vector<double >x;
	std::vector<std::vector<double> > Ax = A;

	if(Determinant(A) != 0){
		for(int i = 0; i < (int)A.size(); i++){
			for(int j = 0; j < (int)A.size(); j++){
				Ax[j][i] = B[j];
			}
			x.push_back(Determinant(Ax)/Determinant(A));
			Ax = A;
		}
		return x;
	}
	else{
		for(int i = 0; i < (int)A.size(); i++) x.push_back(0);
		return x;
	}
}

double Determinant(std::vector<std::vector<double> >a){
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

std::vector<std::vector<double> > L_LT_decomposition(std::vector<std::vector<double> > &A_matrix) {
		std::vector<std::vector<double> >L_matrix(A_matrix.size(), std::vector<double >(A_matrix.size()));
		int i = 0, j = 0, k = 0;
		double sum = 0;
	
		for (i = 0; i < (int)A_matrix.size(); i++) {
			for (j = 0; j < (int)A_matrix.size(); j++) {
				if (i > j) {
					for (k = 0; k <= j-1; k++)
						sum = sum + L_matrix[i][k] * L_matrix[j][k];
						L_matrix[i][j] = (A_matrix[i][j] - sum)/L_matrix[j][j];
						sum = 0;
				}
				else if (i == j) {
					for (k = 0; k <= i-1; k++)
						sum = sum + L_matrix[i][k] * L_matrix[i][k];
						L_matrix[i][i] = sqrt(A_matrix[i][i] - sum);
					sum = 0;
				}
				else
					L_matrix[i][j] = 0;
			}
		}
		return L_matrix;
}
	
std::vector<std::vector<double> > Transpose_Matrix(std::vector<std::vector<double> > &matrix) {
		int i, j;
		double tmp;
	
		for (i = 0; i < (int)matrix.size(); i++) {
			for (j = 0; j < i; j++) {
				tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}
		}
		return matrix;
}

void QR(std::vector<std::vector<double> >A, std::vector<std::vector<double> >&Q, 
        std::vector<std::vector<double> >&R){
	for(int i = 0; i < (int)A.size(); i++){
            for(int j = 0; j < (int)A.size(); j++){
                Q[i].push_back(0);
                R[i].push_back(0);
       }
    }
}

std::vector<std::vector<double> > InreverseMatrix(std::vector<std::vector<double> >A, std::vector<std::vector<double> >E){
    std::vector<std::vector<double> >revA;
     
    for(int i = 0; i < (int)A.size(); i++) revA.push_back(Isolve(A, E[i]));
    
    return Transpose_Matrix(revA);
}

std::vector<std::vector<double> > InreverseMatrix(std::vector<std::vector<double> >L, std::vector<std::vector<double> >U, std::vector<std::vector<double> >E){
    std::vector<std::vector<double> >revA, revL;

   for(int i = 0; i < (int)L.size()-1; i++){
        revL.push_back(Isolve(L,E[i]));
        revA.push_back(Isolve(U, revL[i]));
    }

    return Transpose_Matrix(revA);
}

std::vector<std::vector<double> > CreateIdentityMatrix(int size){
    std::vector<std::vector<double> >I(size);
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            I[i].push_back(0);
        }
    }
    for(int i = 0; i < size; i++) I[i][i] = 1;
    
    return I;
}
