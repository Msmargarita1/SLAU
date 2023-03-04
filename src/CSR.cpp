#include"CSR.h"
#include<vector>

template<typename T>
CSR<T>::CSR(const std::vector<T> &values,const std::vector<T> &cols,const std::vector<T> &rows){
    copy(values.begin(), values.end(), back_inserter(this->values));
    copy(cols.begin(), cols.end(), back_inserter(this->cols));
    copy(rows.begin(), rows.end(), back_inserter(this->rows));
}

template<typename T>
T CSR<T>::operator()(int i, int j) const {
    for (int k = rows[i]; k < rows[i+1]; ++k) {
        if (cols[k] == j) {
            return values[k];
        }
    }
    return 0;
}

template<typename T>
T CSR<T>::operator*(std::vector<T> vec) const {
    std::vector<T> res(row_num);
    for (int i = 0; i < row_num; ++i) {
        for (int j = rows[i]; j < rows[i+1]; ++j) {
            res[i] += values[j] * vec[j];
        }
    }
}