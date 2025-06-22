#include "QuickSort.hpp"

namespace {
void quickSortwrap(std::vector<int>& arr, int low, int high) {
  if (low < high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
      if (arr[j] < pivot) {
        i++;
        std::swap(arr[i], arr[j]);
      }
    }
    std::swap(arr[i + 1], arr[high]);
    int pi = i + 1;

    quickSortwrap(arr, low, pi - 1);
    quickSortwrap(arr, pi + 1, high);
  }
};
}  // namespace

void quickSort(std::vector<int>& arr) {
  if (!arr.empty()) {
    quickSortwrap(arr, 0, arr.size() - 1);
  }
};