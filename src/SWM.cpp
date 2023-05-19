V.resize(N);
    U[0] = (-svkoef[0]) / (-tri_diag_matrix[0][0]);
    V[0] = tri_diag_matrix[0][1] / (-tri_diag_matrix[0][0]);
    for (int i = 1; i < N - 1; i++) {
        V[i] = tri_diag_matrix[i][i + 1] / (-tri_diag_matrix[i][i] - tri_diag_matrix[i][i - 1] * V[i - 1]);
        U[i] = (tri_diag_matrix[i][i - 1] * U[i - 1] - svkoef[i]) / (-tri_diag_matrix[i][i] - tri_diag_matrix[i][i - 1] * V[i - 1]);
    }
    V[N - 1] = 0;
    U[N - 1] = (tri_diag_matrix[N - 1][N - 2] * U[N - 2] - svkoef[N - 1]) / (-tri_diag_matrix[N - 1][N - 1] - tri_diag_matrix[N - 1][N - 2] * V[N - 2]);
    matrix_X[N - 1] = U[N - 1];
    for (int i = N - 1; i >= 0; i--)
        matrix_X[i - 1] = V[i - 1] * matrix_X[i] + U[i - 1];

    return matrix_X;
}