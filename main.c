#include <assert.h>
#include "function/matrix_func.h"

void test1(){
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               0, 1, 4,
                                               5, 6, 0}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {-24, 18, 5,
                                               20, -15, -4,
                                               -5, 4, 1}, 3, 3);


    matrix result = createMatrixFromArray((int[]) {27, -22, 6,
                                                   38, -31, 8,
                                                   -12, 10, -1}, 3, 3);

    if(isMutuallyInverseMatrices(m1, m2)){
        transposeSquareMatrix(&m2);
        m2 = mulMatrices(m1, m2);
    }

    assert(areTwoMatricesEqual(&m2, &result));
}

void test2(){
    matrix m1 = createMatrixFromArray((int[]) {2, -1, 0,
                                               1,  0, 0,
                                               1,  1, 1}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {0, 1, 0,
                                               -1, 2, 0,
                                               -1, -1, 1}, 3, 3);

    matrix result = createMatrixFromArray((int[]) {-1, -4, -1,
                                                   0,  -1, -1,
                                                   1,  1, -1}, 3, 3);

    if(isMutuallyInverseMatrices(m1, m2)){
        transposeSquareMatrix(&m2);
        m2 = mulMatrices(m1, m2);
    }

    assert(areTwoMatricesEqual(&m2, &result));
}


void test3(){
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               0, 1, 4,
                                               0, 0, 1}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, -2, 5,
                                               0, 1, -4,
                                               0, 0, 1}, 3, 3);

    matrix result = createMatrixFromArray((int[]) {12, -10, 3,
                                                   18, -15, 4,
                                                   5, -4, 1}, 3, 3);

    if(isMutuallyInverseMatrices(m1, m2)){
        transposeSquareMatrix(&m2);
        m2 = mulMatrices(m1, m2);
    }

    assert(areTwoMatricesEqual(&m2, &result));
}


void test4(){
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               0, 1, 4,
                                               0, 0, 1}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, -2, 5,
                                               0, 1, -4,
                                               2, 3, 1}, 3, 3);

    matrix result = createMatrixFromArray((int[]) {12, -10, 3,
                                                   18, -15, 4,
                                                   5, -4, 1}, 3, 3);

    if(isMutuallyInverseMatrices(m1, m2)){
        transposeSquareMatrix(&m2);
        m2 = mulMatrices(m1, m2);
    }

    assert(!areTwoMatricesEqual(&m2, &result));
}

void tests(){
    test1();
    test2();
    test3();
    test4();
}

int main(void) {
    tests();

    return 0;
}
