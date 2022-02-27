#ifndef VECTOR_VECTORVOID_H
#define VECTOR_VECTORVOID_H

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

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

// Возвращает 'истина' - если в векторе v нет элементов
// иначе - 'ложь'
bool isEmptyV(vectorVoid *v);

// Возвращает 'истина' - если вектор v полон
// иначе - 'ложь'
bool isFullV(vectorVoid *v);

// Записывает на index-ый элемент вектора v значение, расположенное по адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source);

// Записывает по адресу destination index-ый элемент вектора v
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

// Удаляет последий элемент вектора v
void popBackV(vectorVoid *v);

// Добавление элемента в конец вектора v
void pushBackV(vectorVoid *v, void *source);

#endif //VECTOR_VECTORVOID_H
