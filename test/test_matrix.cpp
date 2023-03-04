#include"../src/CSR.h"
#include<iostream>
#include<gtest/gtest.h>

TEST(matrix, test){
    std::vector<int> values{1, 2, 4, 2, 6};
    std::vector<int> cols{0, 1, 1, 1, 2};
    std::vector<int> rows{0, 2, 3, 5};
    CSR<int>* A = new CSR(values, cols, rows);

    //ASSERT_EQ(A->cols[0],cols[0]);
    //ASSERT_EQ(A->cols[1],cols[1]);
    //ASSERT_EQ(A->cols[2],cols[2]);
    //ASSERT_EQ(A->cols[3],cols[3]);
    std::cout<<A->cols[0];
}