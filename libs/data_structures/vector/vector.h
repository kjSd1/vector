#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stdlib.h>
#include <stdio.h>

typedef struct vector {
    int *data;       //указатель на элементы вектора
    size_t size;     //размер вектора
    size_t capacity; //вместимость вектора
} vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

#endif //VECTOR_VECTOR_H
