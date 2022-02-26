#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct vector {
    int *data;       //указатель на элементы вектора
    size_t size;     //размер вектора
    size_t capacity; //вместимость вектора
} vector;

// Возвращает пустой вектор вместимостью n элементов
vector createVector(size_t n);

// Изменяет вместимость вектора v на newCapacity элементов
void reserve(vector *v, size_t newCapacity);

// Очистка элементов, без освобождения памяти вектора v
void clear(vector *v);

// Освобождает неиспользуемую память вектора v
void shrinkToFit(vector *v);

// освобождает память, выделенную вектор
void deleteVector(vector *v);

// Возвращает 'истина' - если в векторе v нет элементов
// иначе - 'ложь'
bool isEmpty(vector *v);

// Возвращает 'истина' - если вектор v полон
// иначе - 'ложь'
bool isFull(vector *v);

// Возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

// Добавление элемента x в конец вектора v
void pushBack(vector *v, int x);

// Удаление последнего элемента в векторе v
void popBack(vector *v);



#endif //VECTOR_VECTOR_H
