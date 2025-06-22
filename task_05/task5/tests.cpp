#include "sort.hpp"
#include <cassert>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

void test1() {
    int arr[] = {};
    mergeSort(arr, 0);
}

void test2() {
    int arr[] = {5};
    mergeSort(arr, 1);
    assert(arr[0] == 5);
}

void test3() {
    int arr[] = {1, 2, 3, 4, 5};
    mergeSort(arr, 5);
    for (int i = 0; i < 5; i++) {
        assert(arr[i] == i + 1);
    }
}

void test4() {
    int arr[] = {5, 4, 3, 2, 1};
    mergeSort(arr, 5);
    for (int i = 0; i < 5; i++) {
        assert(arr[i] == i + 1);
    }
}

void test5() {
    int arr[] = {2, 1, 2, 1, 3};
    mergeSort(arr, 5);
    assert(arr[0] == 1);
    assert(arr[1] == 1);
    assert(arr[2] == 2);
    assert(arr[3] == 2);
    assert(arr[4] == 3);
}
int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}