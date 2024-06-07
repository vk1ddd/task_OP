//
// Created by ivanu on 07.06.2024.
//
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "matrix_func.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    assert(values != NULL);
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
        assert(values[i] != NULL);
    }
    return (matrix) {values, nRows, nCols};
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);

    matrix result = getMemMatrix(m2.nRows, m1.nCols);
    for (int row = 0; row < m1.nRows; row++)
        for (int col = 0; col < m2.nCols; col++) {
            result.values[row][col] = 0;
            for (int k = 0; k < m1.nCols; k++)
                result.values[row][col] += m1.values[row][k] * m2.values[k][col];
        }

    return result;
}

bool isEMatrix(matrix *m) {
    int row_col = 0;
    while (row_col < m->nCols && row_col < m->nRows) {
        if (m->values[row_col][row_col] != 1)
            return false;
        row_col++;
    }

    return true;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; ++i) {
        free(m->values[i]);
    }
    free(m->values);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix multi = mulMatrices(m1, m2);

    bool result = isEMatrix(&multi);

    freeMemMatrix(&multi);

    return result;
}

void transposeSquareMatrix(matrix *m) {
    int temp;
    for (int row = 0; row < m->nRows; row++) {
        for (int col = 0; col < row; col++) {
            temp = m->values[row][col];
            m->values[row][col] = m->values[col][row];
            m->values[col][row] = temp;
        }
    }
}

bool areTwoMatricesEqual(matrix *m1, matrix *m2) {
    if ((m1->nCols != m2->nCols) || (m1->nRows != m2->nRows))
        return false;

    for (int row = 0; row < m1->nRows; row++) {
        if (memcmp(m1->values[row], m2->values[row], sizeof(int) * m1->nCols) != 0)
            return false;
    }

    return true;
}

void outputMatrix(matrix m) {
    // Пройти по каждой строке матрицы
    for (int i = 0; i < m.nRows; i++) {
        // Вывести верхнюю границу строки
        printf("+");
        for (int k = 0; k < m.nCols; k++) {
            printf("---+");
        }
        printf("\n");

        // Пройти по каждому столбцу в текущей строке
        for (int j = 0; j < m.nCols; j++) {
            // Вывести значение элемента в текущей позиции
            printf("| %d ", m.values[i][j]);
        }
        // Вывести символ для границы справа
        printf("|\n");
    }

    // Вывести нижнюю границу матрицы
    printf("+");
    for (int k = 0; k < m.nCols; k++) {
        printf("---+");
    }
    printf("\n");
}
