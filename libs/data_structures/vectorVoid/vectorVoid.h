#ifndef VECTOR_VECTORVOID_H
#define VECTOR_VECTORVOID_H

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct vectorVoid {
    void *data;          // указатель на нулевой элемент вектора
    size_t size;         // размер вектора
    size_t capacity;     // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
    // например, если вектор хранит int -
    // то поле baseTypeSize = sizeof(int)
    // если вектор хранит float -
    // то поле baseTypeSize = sizeof(float)
}vectorVoid;

// Возвращает структуру vectorVoid c вместимостью n элементов и базовым размером baseTypeSize
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// зменяет вместимость вектора v на newCapacity элементов
void reserveV(vectorVoid *v, size_t newCapacity);

// Очистка элементов, без освобождения памяти вектора v
void clearV(vectorVoid *v);

// Освобождает неиспользуемую память вектора v
void shrinkToFitV(vectorVoid *v);

// Освобождает память, выделенную вектор
void deleteVectorV(vectorVoid *v);

#endif //VECTOR_VECTORVOID_H
