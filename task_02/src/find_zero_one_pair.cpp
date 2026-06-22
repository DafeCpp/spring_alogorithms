#include "./find_zero_one_pair.h"

#include <stdexcept>

int FindZeroOnePair(const std::vector<int>& values) {
  if (values.size() < 2) {
    throw std::invalid_argument("Array must contain at least two elements");
  }
  if (values[0] != 0) {
    throw std::invalid_argument("The first element must be zero");
  }
  if (values[values.size() - 1] != 1) {
    throw std::invalid_argument("The last element must be one");
  }

  int lo = 0;
  int hi = static_cast<int>(values.size()) - 1;
  while (hi - lo > 1) {
    const int mid = lo + (hi - lo) / 2;
    if (values[mid] == 0) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}
