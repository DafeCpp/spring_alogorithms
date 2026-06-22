#include "task2.hpp"

#include <vector>

int FindPair(const std::vector<int>& vec) {
  if (vec.size() < 2) {
    return -1;
  }

  int left = 0;
  std::size_t right = (vec.size() - 1);

  while (right - left > 1) {
    int center = (right + left) / 2;
    if (vec[center] == 0) {
      left = center;
    } else {
      right = center;
    }
  }

  return left;
}