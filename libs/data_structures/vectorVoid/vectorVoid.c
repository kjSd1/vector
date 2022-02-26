#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    int *data = calloc(n, baseTypeSize);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vectorVoid) {data, 0, n, baseTypeSize};
}

void reserve(vectorVoid *v, size_t newCapacity) {
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

void clear(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFit(vectorVoid *v) {
    reserve(v, v->size);
}

void deleteVector(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}
