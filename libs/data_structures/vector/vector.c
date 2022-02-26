#include "vector.h"

vector createVector(size_t n) {
    int *data = calloc(n, sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else if (v->capacity != newCapacity) {
        v->data = realloc(v->data, newCapacity * sizeof(int));
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(2);
        }
    }
    v->capacity = newCapacity;
    if (v->size > v->capacity)
        v->size = v->capacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = (int*)realloc(v->data, v->size * sizeof(int));
}

void deleteVector(vector *v) {
    free(v->data);
}
