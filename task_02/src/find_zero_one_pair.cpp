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
    throw std::invalid_argument("The last element must be zero");
  }

  for (int i = 0; i < static_cast<int>(values.size()) - 1; i++) {
    if (values[i] == 0 && values[i + 1] == 1) {
      return i;
    }
  }

  return -1;
}
