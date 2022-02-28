#ifndef VECTOR_MATRIX_H
#define VECTOR_MATRIX_H

#include "malloc.h"
#include "stdio.h"

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows;    // количество рядов
    int nCols;    // количество столбцов
}matrix;

typedef struct position{
    int rowIndex;
    int colIndex;
}position;

// Возвращает матрицу размером nRows на nCols
matrix getMemMatrix(int nRows, int nCols);

// Размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols
matrix* getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// Освобождает память, выделенную под хранение матрицы m. Процесс освобождения изображен на рисунке
void freeMemMatrix(matrix *m);

// Освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices);

// Ввод матрицы m
void inputMatrix(matrix *m);

// Ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix *ms, int nMatrices);

// Вывод матрицы m
void outputMatrix(matrix m);

// Вывод массива из nMatrices матриц, хранящейся по адресу ms
void outputMatrices(matrix *ms, int nMatrices);

#endif //VECTOR_MATRIX_H
