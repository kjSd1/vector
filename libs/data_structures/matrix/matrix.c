#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int**) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i ++)
        values[i] = (int*)malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix* getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *matrixArray = (matrix*)calloc(nMatrices, sizeof(matrix));
    for (int index = 0; index < nMatrices; index++)
        matrixArray[index] = getMemMatrix(nRows, nCols);
    return matrixArray;
}

void freeMemMatrix(matrix *m) {
    for (int index = 0; index < m->nRows; index++)
        free(m->values[index]);
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int index = 0; index < nMatrices; index++)
        freeMemMatrix(ms++);
}

void inputMatrix(matrix *m) {
    for (int indexRows = 0; indexRows < m->nRows; indexRows++)
        for (int indexCols = 0; indexCols < m->nCols; indexCols++)
            scanf("%d", &m->values[indexRows][indexCols]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int index = 0; index < nMatrices; index++)
        inputMatrix(&ms[index]);
}

void outputMatrix(matrix m) {
    for (int indexRows = 0; indexRows < m.nRows; indexRows++) {
        for (int indexCols = 0; indexCols < m.nCols; indexCols++)
            printf("%d ", m.values[indexRows][indexCols]);
        printf("\n");
    }
    printf("\n");
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int index = 0; index < nMatrices; index++) {
        printf("------------------------ Matrix number is %d\n", index);
        outputMatrix(ms[index]);
    }
}

