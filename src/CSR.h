#include<vector>

template<typename T>
class CSR {
    public:
        int row_num;
        int col_num;
        std::vector<T> values;
        std::vector<T> cols;
        std::vector<T> rows;

        CSR(const std::vector<T> &values,const std::vector<T> &cols,const std::vector<T> &rows){
        }
        
        T operator()(int i, int j) const {
        }

        T operator*(std::vector<T> vec) const {
        }
};