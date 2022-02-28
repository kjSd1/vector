#include <stdio.h>
#include <D:/_Work/_GitHub/vector/libs/data_structures/vector/vector.h>
#include <D:/_Work/_GitHub/vector/libs/data_structures/vectorVoid/vectorVoid.h>
#include <D:/_Work/_GitHub/vector/libs/data_structures/matrix/matrix.h>
#include <stdint.h>

void test_vector_creatVector_sizeMax() {
    vector v = createVector(SIZE_MAX);
}

void test_vector_creatVector_notBigCapacity() {
    vector v = createVector(5);
    assert(v.data != NULL);
    assert(v.size == 0);
    assert(v.capacity == 5);
    deleteVector(&v);
}

void test_vector_creatVector_zeroCapacity() {
    vector v = createVector(0);
    assert(v.data != NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);
    deleteVector(&v);
}

void test_vector_creatVector() {
    //test_vector_creatVectorSizeMaxCapacity();     // Выводит bad alloc и заканчивает выполнение программы
    test_vector_creatVector_notBigCapacity();
    test_vector_creatVector_zeroCapacity();
}

void test_vector_reserve_emptyVector() {
    vector v = createVector(0);
    reserve(&v, 2);
    assert(v.capacity == 2);
    assert(v.data != NULL);
    assert(v.size == 0);
    deleteVector(&v);
}

void test_vector_reserve_notBigNumberCapacity() {
    vector v = createVector(5);
    reserve(&v, 0);
    assert(v.capacity == 0);
    assert(v.data == NULL);
    assert(v.size == 0);
    deleteVector(&v);
}

void test_vector_reserve_sizeMaxChange() {
    vector v = createVector(5);
    reserve(&v, SIZE_MAX);
    assert(v.capacity == 0);
    assert(v.data != NULL);
    assert(v.size == 0);
    deleteVector(&v);
}

void test_vector_reserve() {
    test_vector_reserve_emptyVector();
    test_vector_reserve_notBigNumberCapacity();
    //test_vector_reserve_sizeMaxChange();   // Выводит bad alloc и заканчивает выполнение программы
}

void test_vector_pushBack_emptyVectorAndFullVector() {
    vector v = createVector(0);
    pushBack(&v, 3);
    pushBack(&v, 4);
    pushBack(&v, 5);
    assert(v.data != NULL);
    assert(v.size == 3);
    assert(v.capacity == 4);
    deleteVector(&v);
}

void test_vector_pushBack() {
    test_vector_pushBack_emptyVectorAndFullVector();
}

void test_vector_shrinkToFit_notEmptyVector() {
    vector v = createVector(5);
    pushBack(&v, 3);
    shrinkToFit(&v);
    assert(v.data != NULL);
    assert(v.size == 1);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test_vector_shrinkToFit_emptyVector() {
    vector v = createVector(5);
    shrinkToFit(&v);
    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);
    deleteVector(&v);
}

void test_vector_shrinkToFit() {
    test_vector_shrinkToFit_notEmptyVector();
    test_vector_shrinkToFit_emptyVector();
}

void test_vector_popBack_notEmptyVector() {
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
    deleteVector(&v);
}

void test_vector_popBack_emptyVector() {
    vector v = createVector(0);
    popBack(&v);
}

void test_vector_popBack() {
    test_vector_popBack_notEmptyVector();
    //test_vector_popBack_EmptyVector();   // Vector is empty, code 1
}

void test_vector_atVector_fullVector() {
    vector v = createVector(4);
    pushBack(&v, 3);
    pushBack(&v, 2);
    pushBack(&v, 1);
    int *ptrIndex = atVector(&v, 2);
    assert(*ptrIndex == 1);
    deleteVector(&v);
}

void test_vector_atVector_emptyVector() {
    vector v = createVector(0);
    atVector(&v, 2);
}

void test_vector_atVector() {
    test_vector_atVector_fullVector();
    //test_vector_atVector_emptyVector(); // IndexError: a[2] is not exists
}

void test_vector_back_notBigSizeVector() {
    vector v = createVector(0);
    pushBack(&v, 3);
    pushBack(&v, 2);
    pushBack(&v, 1);
    int *resultIndex = back(&v);
    assert(*resultIndex ==  1);
    deleteVector(&v);
}

void test_vector_back_fullVector() {
    vector v = createVector(0);
    pushBack(&v, 3);
    pushBack(&v, 2);
    pushBack(&v, 1);
    pushBack(&v, 6);
    int *resultIndex = back(&v);
    assert(*resultIndex ==  6);
    deleteVector(&v);
}

void test_vector_back_emptyVector() {
    vector v = createVector(0);
    int *resultIndex = back(&v);
}

void test_vector_back() {
    test_vector_back_notBigSizeVector();
    test_vector_back_fullVector();
    //test_vector_back_emptyVector();   // Vector is empty, code 1
}

void test_vector_front_emptyVector() {
    vector v = createVector(0);
    int *resultIndex = front(&v);
}

void test_vector_front_fullVector() {
    vector v = createVector(0);
    pushBack(&v, 3);
    pushBack(&v, 2);
    pushBack(&v, 1);
    pushBack(&v, 6);
    int *resultIndex = front(&v);
    assert(*resultIndex == 3);
    deleteVector(&v);
}

void test_vector_front() {
    //test_vector_front_emptyVector();   // Vector is empty, code 1
    test_vector_front_fullVector();
}

// Для некоторых функций не было написанно тестов, так как они повсеместно использовались в прошлых лабах,
// 5а, array.h ...
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

void test_vectorVoid_creatVector() {
    vectorVoid v = createVectorV(4, sizeof(char));
    assert(&v.data[0] + 1 == &v.data[1]);
    deleteVectorV(&v);
}

void test_vectorVoid_reserve_emptyVector() {
    vectorVoid v = createVectorV(2, sizeof(float));
    reserveV(&v, 6);
    assert(v.capacity == 6);
    deleteVectorV(&v);
}

void test_vectorVoid_reserve_decreaseCapacity() {
    vectorVoid v = createVectorV(4, sizeof(float));
    int a = 1;
    int b = 2;
    int c = 3;
    pushBackV(&v, &a);
    pushBackV(&v, &b);
    pushBackV(&v, &c);
    assert(!isFullV(&v));
    reserveV(&v, 2);
    assert(isFullV(&v));
    deleteVectorV(&v);
}

void test_vectorVoid_reserve() {
    test_vectorVoid_reserve_emptyVector();
    test_vectorVoid_reserve_decreaseCapacity();
}

void test_vectorVoid_pushBackVAndGetVectorValueV_Int() {
    size_t n;
    scanf("%zd", &n);

    vectorVoid v = createVectorV(0, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        getVectorValueV(&v, i, &x);
        printf("%d ", x);
    }
    deleteVectorV(&v);
}

void test_vectorVoid_pushBackVAndGetVectorValueV_Float() {
    size_t n;
    scanf("%zd", &n);

    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);
        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);
        printf("%f ", x);
    }
    deleteVectorV(&v);
}

void test_vectorVoid_getVectorValueV_Error1() {
    vectorVoid v = createVectorV(3, sizeof(int));
    int a = 1;
    int b = 2;

    pushBackV(&v, &a);
    pushBackV(&v, &b);

    int result;
    getVectorValueV(&v, 2, &result);
}

void test_vectorVoid_getVectorValueV_Error2() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int result;
    getVectorValueV(&v, 0, &result);
}

void test_vectorVoid_setVectorValueV_EmptyVectorError() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int add = 2;
    setVectorValueV(&v, 0, &add);
}

void test_vectorVoid_setVectorValueV_FullVector() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int add1 = 1;
    pushBackV(&v, &add1);
    int add2 = 2;
    pushBackV(&v, &add2);
    int add3 = 3;
    pushBackV(&v, &add3);

    int change = 99;
    setVectorValueV(&v, 0, &change);

    int result;
    getVectorValueV(&v, 0, &result);
    assert(result == 99);
    assert(v.capacity == 4);
    assert(v.size == 3);
    deleteVectorV(&v);
}


void test_vectorVoid_setVectorValueV() {
    //test_vectorVoid_setVectorValueV_EmptyVectorError(); // IndexError: a[0] is not exist - Работа корректна
    test_vectorVoid_setVectorValueV_FullVector();
}

void test_vectorVoid() {
    test_vectorVoid_creatVector();
    test_vectorVoid_reserve();

    //test_vectorVoid_pushBackVAndGetVectorValueV_Int(); // Работа корректна
    //test_vectorVoid_pushBackVAndGetVectorValueV_Float(); // Работа корректна
    //test_vectorVoid_getVectorValueV_Error1(); // IndexError: a[2] is not exists - Работа корректна
    //test_vectorVoid_getVectorValueV_Error2(); // IndexError: a[0] is not exists - Работа корректна
    test_vectorVoid_setVectorValueV();

    // isFull и isEmpty и clearV - практически идентичны функциям vector
    // shrinkToFit(); // При усливии правильный работы reserve работает правильно
    // Так как такая же как и в vector
}


void test_matrix_inputOutput() {
    matrix *matrix1 = getMemArrayOfMatrices(3, 3, 3);
    inputMatrices(matrix1, 3);
    outputMatrices(matrix1, 3);
}

void test_matrix() {
    test_matrix_inputOutput();
}

void test() {
    //test_vector();
    //test_vectorVoid();
    test_matrix();
}

int main() {
    test();

    return 0;
}
