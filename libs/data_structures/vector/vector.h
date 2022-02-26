#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stdlib.h>

typedef struct vector {
    int *data; //указатель на элементы вектора
    size_t size; //размер вектора
    size_t capacity; //вместимость вектора
} vector;

#endif //VECTOR_VECTOR_H
