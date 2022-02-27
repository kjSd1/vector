#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    int *data = calloc(n, baseTypeSize);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vectorVoid) {data, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else if (v->capacity != newCapacity) {
        v->data = realloc(v->data, newCapacity * v->baseTypeSize);
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }

    v->capacity = newCapacity;
    if (v->size > v->capacity)
        v->size = v->capacity;
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (index >= v->size)
        fprintf(stderr, "IndexError: a[%d] is not exists", index);
    char *source = (char*)v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index >= v->size)
        fprintf(stderr, "IndexError: a[%d] is not exists", index);
    char *destination = (char*)v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void pushBackV(vectorVoid *v, void *source) {
    if (v->capacity == 0)
        reserveV(v, 1);
    else if (isFullV(v))
        reserveV(v, v->capacity * 2);
    v->size++;
    setVectorValueV(v, v->size - 1, source);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }
    v->size--;
}
