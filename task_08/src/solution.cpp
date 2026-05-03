#include "solution.hpp"

int separation(std::vector<int>& arr, int left, int right){
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++){
        if (arr[j] <= pivot){
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[right]);
    return i;
}


int quickSelect(std::vector<int>& arr, int left, int right, int k){
    if (left == right) return arr[left];
    int pivotIndex = separation(arr, left, right);

    if (pivotIndex == k){
        return arr[k];
    }
    else if (pivotIndex > k){
        return quickSelect(arr, left, pivotIndex - 1, k);
    }
    else{
        return quickSelect(arr, pivotIndex + 1, right, k);
    }
}