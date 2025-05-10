#include "k_stat.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>

int Partition(std::vector<int>& arr, int left, int right) {
  int pivot_index = 0;
  if (right - left + 1) pivot_index = left + rand() % (right - left + 1);

  int pivot_value = arr[pivot_index];

  std::swap(arr[pivot_index], arr[right]);

  int store_index = left;
  for (int i = left; i < right; i++) {
    if (arr[i] < pivot_value) {
      std::swap(arr[i], arr[store_index]);
      store_index++;
    }
  }

  std::swap(arr[store_index], arr[right]);
  return store_index;
}

int QuickSelect(std::vector<int>& arr, int left, int right, int k) {
  if (left == right) return arr[left];

  int pivot_index = Partition(arr, left, right);

  if (k == pivot_index)
    return arr[k];
  else if (k < pivot_index)
    return QuickSelect(arr, left, pivot_index - 1, k);
  else
    return QuickSelect(arr, pivot_index + 1, right, k);
}

int FindKStat(std::vector<int>& arr, int n) {
  if (n < 0 || n >= arr.size()) {
    std::cerr << "Invalid n: out of bounds!" << '\n';
    return -1;
  }
  return QuickSelect(arr, 0, arr.size() - 1, n);
}