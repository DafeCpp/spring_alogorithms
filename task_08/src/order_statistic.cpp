#include "order_statistic.hpp"

#include <utility>

static int Partition(std::vector<int>& values, int left, int right) {
  const int pivot = values[left + (right - left) / 2];
  int first = left;
  int second = right;

  while (first <= second) {
    while (values[first] < pivot) {
      ++first;
    }
    while (values[second] > pivot) {
      --second;
    }
    if (first <= second) {
      std::swap(values[first], values[second]);
      ++first;
      --second;
    }
  }

  return first;
}

int KthOrderStatistic(std::vector<int> values, int statistic) {
  const int target = statistic - 1;
  int left = 0;
  int right = static_cast<int>(values.size()) - 1;

  while (left < right) {
    const int border = Partition(values, left, right);
    if (target < border) {
      right = border - 1;
    } else {
      left = border;
    }
  }

  return values[target];
}
