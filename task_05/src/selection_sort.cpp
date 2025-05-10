#include "selection_sort.hpp"

int Maxx(int a, int b) { return a >= b ? a : b; }
int Minn(int a, int b) { return a <= b ? a : b; }

std::vector<int> Slice(const std::vector<int>& vector, const size_t from,
                       const size_t to) {
  if (from < to)
    return std::vector<int>{vector.begin() + from, vector.begin() + to};
  else
    return std::vector<int>{};
}

void SelectionSort(std::vector<int>& vec) {
  int n = vec.size();

  for (size_t i = 0; i < n; i++) {
    int min_i = i;
    for (size_t j = i; j < n; j++) {
      vec[min_i] > vec[j] ? min_i = j : min_i = min_i;
    }
    std::swap(vec[i], vec[min_i]);
  }
}