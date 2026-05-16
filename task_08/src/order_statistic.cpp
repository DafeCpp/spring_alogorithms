#include "order_statistic.h"

#include <utility>

namespace {

int Partition(std::vector<int>& values, int left, int right) {
  const int pivot = values[right];
  int store_index = left;

  for (int i = left; i < right; ++i) {
    if (values[i] <= pivot) {
      std::swap(values[i], values[store_index]);
      ++store_index;
    }
  }

  std::swap(values[store_index], values[right]);
  return store_index;
}

}  // namespace

int GetOrderStatistic(std::vector<int> values, int order) {
  int left = 0;
  int right = static_cast<int>(values.size()) - 1;
  const int target = order - 1;

  while (left <= right) {
    const int pivot_index = Partition(values, left, right);
    if (pivot_index == target) {
      return values[pivot_index];
    }
    if (pivot_index < target) {
      left = pivot_index + 1;
    } else {
      right = pivot_index - 1;
    }
  }

  return values[target];
}
