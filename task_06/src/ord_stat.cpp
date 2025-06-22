#include "ord_stat.hpp"

int ordstat(std::vector<int>& arr, int k) {
  int left = 0;
  int right = arr.size() - 1;

  while (left <= right) {
    int pivot_index = left + rand() % (right - left + 1);
    int pivotValue = arr[pivot_index];
    std::swap(arr[pivot_index], arr[right]);

    int storeIndex = left;
    for (int i = left; i < right; i++) {
      if (arr[i] <= pivotValue) {
        std::swap(arr[i], arr[storeIndex]);
        storeIndex++;
      }
    }
    std::swap(arr[storeIndex], arr[right]);

    if (storeIndex == k)
      return arr[storeIndex];
    else if (storeIndex < k)
      left = storeIndex + 1;
    else
      right = storeIndex - 1;
  }

  return -1;
}