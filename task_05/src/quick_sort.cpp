#include "quick_sort.hpp"

#include <algorithm>
#include <vector>

static void QuickSortInplace(std::vector<double>& arr, int left, int right) {
  if (left >= right) return;
  double pivot = arr[right];
  int i = left;
  for (int j = left; j < right; ++j) {
    if (arr[j] < pivot) {
      std::swap(arr[i], arr[j]);
      ++i;
    }
  }
  std::swap(arr[i], arr[right]);
  QuickSortInplace(arr, left, i - 1);
  QuickSortInplace(arr, i + 1, right);
}

// обертка
std::vector<double> QuickSort(const std::vector<double>& input) {
  std::vector<double> arr = input;
  if (!arr.empty()) QuickSortInplace(arr, 0, arr.size() - 1);
  return arr;
}