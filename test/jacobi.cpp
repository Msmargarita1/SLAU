#include <iostream>
#include <vector>
#include "tri_diag_matrix.h"

std::vector<double> Jacobi(int N, matrix* M, std::vector<double> b, std::vector<double> X) {
    double eps = 0.001;
    double norm;
    auto temp = new double[N];
    for(int i = 0; i < N; i++){
        temp[i] = b[i];
    }
    int cnt = 0;
    do {
        for (int i = 0; i < N; i++) 
        {
            temp[i] = X[i];
            for (int j = 0; j < N; j++) 
                if (i != j)
                    temp[i] -= M[i][j] * b[j];
            temp[i] /= M[i][i];
        }
        norm = abs(b[0] - temp[0]);
        for (int k = 0; k < N; k++) 
        {
            if (abs(b[k] - temp[k]) > norm)
                norm = abs(b[k] - temp[k]);
            b[k] = temp[k];
        }
        cnt++;  
    } 
    while (norm > eps);
    delete temp;
}