#include "sort.hpp"

namespace {
    void merge(int arr[], int left, int mid, int right, int temp[]) {
        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (i = 0; i < k; i++) {
            arr[left + i] = temp[i];
        }
    }

    void mergeSortHelper(int arr[], int left, int right, int temp[]) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortHelper(arr, left, mid, temp);
            mergeSortHelper(arr, mid + 1, right, temp);
            merge(arr, left, mid, right, temp);
        }
    }
}

void mergeSort(int arr[], int size) {
    if (size <= 1) return;
    int* temp = new int[size];
    mergeSortHelper(arr, 0, size - 1, temp);
    delete[] temp;
}