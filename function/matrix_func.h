//
// Created by ivanu on 07.06.2024.
//

#ifndef TASK_OP_MATRIX_FUNC_H
#define TASK_OP_MATRIX_FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct matrix {
    int **values; //элементы  матрицы
    int nRows; //количество  рядов
    int nCols; //количество  столбцов
} matrix;

matrix getMemMatrix(int nRows, int nCols);

matrix createMatrixFromArray(const int *a, int nRows, int nCols);

matrix mulMatrices(matrix m1, matrix m2);

bool isEMatrix(matrix *m);

void freeMemMatrix(matrix *m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

void transposeSquareMatrix(matrix *m);

bool areTwoMatricesEqual(matrix *m1, matrix *m2);

void outputMatrix(matrix m);

#endif //TASK_OP_MATRIX_FUNC_H
