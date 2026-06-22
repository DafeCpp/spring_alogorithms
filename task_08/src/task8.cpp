#include "task8.hpp"

#include <algorithm>

int findKthOrderStatistic(const std::vector<int>& arr, int K) {
  std::vector<int> sorted = arr;
  std::sort(sorted.begin(), sorted.end());

  return sorted[K - 1];
}