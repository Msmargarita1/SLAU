#include <iostream>
#include <vector>
#include <cmath>
#include "tri_diag_matrix.h"

double norm(matrix* m, int n, int m) {
    int i, j;
    double sum = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            sum += (m[i][j] * m[i][j]);
        }
    }
    sum = sqrt(sum);
    return sum;
}

std::vector<double> Jacobi(int N, matrix* M, std::vector<double> B) {
    double eps = 0.001;
    auto X = new double[N];

    for(int i = 0; i < N; i++){
        X[i] = B[i];
    }
    double s = 0;
    do {
        for (i = 0; i < N; i++) {
            p = B[i];
            for (j = 0; j < N; j++) {
                p = p + M[i][j] * X[j];
            }
            s += (X[i] - p) * (X[i] - p);
            X[i] = p;
        }
    }
    while (std::sqrt(s) >= eps * (1 - norm(M, N, N) / (1 - norm(M, N, N))));
    delete X;
}