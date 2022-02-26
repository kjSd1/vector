#include <stdio.h>
#include <D:/_Work/_GitHub/vector/libs/data_structures/vector/vector.h>
#include <stdint.h>

void test_vector_creatVector1() {
    vector v = createVector(SIZE_MAX);
}

void test_vector_creatVector2() {
    vector v = createVector(5);
    assert(v.data != NULL);
    assert(v.size == 0);
    assert(v.capacity == 5);
}

void test_vector_creatVector3() {
    vector v = createVector(0);
    assert(v.data != NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);
}

void test_vector_creatVector() {
    //test_vector_creatVector1();     // Выводит bad alloc и заканчивает выполнение программы
    test_vector_creatVector2();
    test_vector_creatVector3();
}

void test_vector_reserve1() {
    vector v = createVector(0);
    reserve(&v, 2);
    assert(v.capacity == 2);
    assert(v.data != NULL);
    assert(v.size == 0);
}

void test_vector_reserve2() {
    vector v = createVector(5);
    reserve(&v, 0);
    assert(v.capacity == 0);
    assert(v.data == NULL);
    assert(v.size == 0);
}

void test_vector_reserve3() {
    vector v = createVector(5);
    reserve(&v, SIZE_MAX);
    assert(v.capacity == 0);
    assert(v.data != NULL);
    assert(v.size == 0);
}

void test_vector_reserve() {
    test_vector_reserve1();
    test_vector_reserve2();
    //test_vector_reserve3();   // Выводит bad alloc и заканчивает выполнение программы
}



void test_vector_pushBack_emptyVectorAndFullVector() {
    vector v = createVector(0);
    pushBack(&v, 3);
    pushBack(&v, 4);
    pushBack(&v, 5);
    assert(v.data != NULL);
    assert(v.size == 3);
    assert(v.capacity == 4);
}

void test_vector_pushBack1() {
    vector v = createVector(3);
    pushBack(&v, 3);
    pushBack(&v, 4);
    pushBack(&v, 5);
    assert(v.data != NULL);
    assert(v.size == 3);
    assert(v.capacity == 3);
}

void test_vector_pushBack() {
    test_vector_pushBack_emptyVectorAndFullVector();
    test_vector_pushBack1();
}

void test_vector_shrinkToFit() {
    vector v = createVector(5);
    pushBack(&v, 3);
    shrinkToFit(&v);
    assert(v.data != NULL);
    assert(v.size == 1);
    assert(v.capacity == 1);
}

void test_vector_popBack1() {
    vector v = createVector(5);
    pushBack(&v, 3);
    pushBack(&v, 2);
    pushBack(&v, 1);
    popBack(&v);
    assert(v.data != NULL);
    assert(v.size == 2);
    assert(v.capacity == 5);
    assert(v.data[0] == 3);
    assert(v.data[1] == 2);
}

void test_vector_popBack2() {
    vector v = createVector(0);
    popBack(&v);
}

void test_vector_popBack() {
    test_vector_popBack1();
    //test_vector_popBack2();   // Vector is empty, code 1
}

void test_vector_atVectorFull() {
    vector v = createVector(4);
    pushBack(&v, 3);
    pushBack(&v, 2);
    pushBack(&v, 1);
    int *ptrIndex = atVector(&v, 2);
    assert(*ptrIndex == 1);
}

void test_vector_atVectorEmpty() {
    vector v = createVector(0);
    atVector(&v, 2);
}

void test_vector_atVector() {
    test_vector_atVectorFull();
    //test_vector_atVectorEmpty(); // IndexError: a[2] is not exists
}

void test_vector_back() {
    vector v = createVector(0);
    pushBack(&v, 3);
    pushBack(&v, 2);
    pushBack(&v, 1);
    int *resultIndex = back(&v);
    assert(*resultIndex ==  1);
}

void test_vector_front() {
    vector v = createVector(0);
    pushBack(&v, 3);
    pushBack(&v, 2);
    pushBack(&v, 1);
    int *resultIndex = front(&v);
    assert(*resultIndex == 3);
}

// Для некоторых функций не было написанно тестов, так как они повсеместно использовались в прошлых лабах,
// 5а array.h ...
void test_vector() {
    test_vector_creatVector();
    test_vector_reserve();
    test_vector_pushBack();
    test_vector_popBack();
    test_vector_shrinkToFit();
    test_vector_atVector();
    test_vector_back();
    test_vector_front();
}

int main() {
    test_vector();

    return 0;
}
