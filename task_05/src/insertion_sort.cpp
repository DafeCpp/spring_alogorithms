#include "insertion_sort.hpp"

void InsertionSort(std::vector<int>& vec) {
  int n = vec.size();

  for (size_t i = 0; i < n; i++) {
    for (size_t j = i; j > 0; j--) {
      if (vec[j] < vec[j - 1]) {
        std::swap(vec[j], vec[j - 1]);
        continue;
      }
      if (vec[j] >= vec[j - 1]) {
        break;
      }
    }
  }
}