#include "smallest.hpp"
#include <algorithm>

int partition(std::vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

int quickSelect(std::vector<int>& arr, int left, int right, int K) {
    if (left == right) {
        return arr[left];
    }
    
    int pivotIndex = partition(arr, left, right);
    
    if (K == pivotIndex) {
        return arr[K];
    } else if (K < pivotIndex) {
        return quickSelect(arr, left, pivotIndex - 1, K);
    } else {
        return quickSelect(arr, pivotIndex + 1, right, K);
    }
}

int Smallest(std::vector<int>& arr, int K) {
    int n = arr.size();
    return quickSelect(arr, 0, n - 1, K - 1);
}