#ifndef GradMethod 
#define GradMethod

#include "../tri_diag_matrix.h"

template<typename T>
std::pair<std::vector<T>, std::pair<size_t, std::vector<double>>> Naiskor_grad_method
(const std::vector<T>& x0, const std::vector<T>& b, double accuracy, CSR<T> matrix) 
{
    std::vector<T> x = x0;
    std::vector<T> r(matrix,matrix.size());
    for(int i = 0; i < matrix,matrix.size(); i++)
        r[i] = b[i] - matrix.matrix[i].value * x[i];
    size_t count = 0;
    std::vector<double> nv{std::sqrt(r * r)};
    std::vector<T> Ar(x0.size());
    double alpha;
    while (nv[count] > accuracy) {
        std::vector<T> r(matrix,matrix.size());
    for(int i = 0; i < matrix,matrix.size(); i++)
        Ar[i] = matrix.matrix[i].value * r[i];
        
        alpha = r * r / (r * Ar);
        x = x + alpha * r;
        r = r - alpha * Ar;
        nv.push_back(std::sqrt(r * r));
        count++;
    }
    return std::make_pair(x, std::make_pair(count, nv));
}

#endif