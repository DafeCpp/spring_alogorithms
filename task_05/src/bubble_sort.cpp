#include "bubble_sort.hpp"

void BubbleSort(std::vector<int>& vec) {
  int n = vec.size();

  while (n > 1) {
    for (size_t j = 0; j < n - 1; j++) {
      if (vec[j] > vec[j + 1]) {
        std::swap(vec[j], vec[j + 1]);
      }
    }
    n--;
  }
}