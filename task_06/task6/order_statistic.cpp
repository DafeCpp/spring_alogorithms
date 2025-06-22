#include "order_statistic.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdexcept>

namespace {
    int partition(int *array, int left, int right, int pivot_index) {
        int pivot_value = array[pivot_index];
        std::swap(array[pivot_index], array[right]);
        int store_index = left;
        for (int i = left; i < right; ++i) {
            if (array[i] < pivot_value) {
                std::swap(array[i], array[store_index]);
                ++store_index;
            }
        }
        std::swap(array[store_index], array[right]);
        return store_index;
    }
}

int order_statistic(int *array, int n, int k) {
    if (k < 0 || k >= n) {
        throw std::invalid_argument("k is out of bounds");
    }
    static bool first_time = true;
    if (first_time) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        first_time = false;
    }
    int left = 0;
    int right = n - 1;
    while (true) {
        if (left == right) {
            return array[left];
        }
        int pivot_index = left + std::rand() % (right - left + 1);
        pivot_index = partition(array, left, right, pivot_index);
        if (k == pivot_index) {
            return array[k];
        } else if (k < pivot_index) {
            right = pivot_index - 1;
        } else {
            left = pivot_index + 1;
        }
    }
}