#ifndef SLAU_SwM_H
#define SLAU_SwM_H

#include<iostream>
#include<vector>
#include<array>
#include "../tri_diag_matrix.h"

class sMethod {
private:
    std::vector<double> svkoef;
    std::vector<std::vector<double>> tri_diag_matrix;
public:
    sMethod(std::vector<double>a, std::vector<double> b, std::vector<double> c, std::vector<double> free);
    std::vector<double> sw();
};
#endif
