#include "order_statistic.hpp"
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>

void test1() {
    int base[] = {3, 1, 4, 2, 5};
    int n = 5;
    int sorted[] = {1, 2, 3, 4, 5};
    for (int k = 0; k < n; ++k) {
        int arr[n];
        std::copy(base, base + n, arr);
        assert(order_statistic(arr, n, k) == sorted[k]);
    }
}

void test2() {
    int arr[] = {42};
    assert(order_statistic(arr, 1, 0) == 42);
}

void test3() {
    int base[] = {2, 1, 2, 1, 3};
    int n = 5;
    int sorted[] = {1, 1, 2, 2, 3};
    for (int k = 0; k < n; ++k) {
        int arr[n];
        std::copy(base, base + n, arr);
        assert(order_statistic(arr, n, k) == sorted[k]);
    }
}
int main() {
    test1();
    test2();
    test3();
    return 0;
}