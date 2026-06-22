#include "find_one_after_zero.hpp"

int FindOneAfterZero(std::size_t size, const std::vector<int>& vec) {
  if (size < 2) return -1;

  std::size_t left{0};
  std::size_t right{size - 1};
  while (right - left > 1) {
    std::size_t mid = (left + right) / 2;
    if (vec[mid] == 1) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return left;
}
