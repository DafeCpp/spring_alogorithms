#include "transition.hpp"

int FindZeroOneBoundary(const std::vector<int>& values) {
  int left = 0;
  int right = static_cast<int>(values.size()) - 1;

  while (left < right) {
    const int middle = left + (right - left) / 2;
    if (values[middle] == 0) {
      left = middle + 1;
    } else {
      right = middle;
    }
  }

  return left - 1;
}
