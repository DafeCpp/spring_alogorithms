#include "task2.hpp"

int findBoundary(const std::vector<int>& arr) {
  int left = 0;
  int right = arr.size() - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == 0) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return left - 1;
}