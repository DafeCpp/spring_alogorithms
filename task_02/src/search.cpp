#include "search.hpp"

int Search(std::vector<int>& cont) {
  int left = 0;
  int right = size(cont) - 1;
  while (right - left > 1) {
    int middle = left + (right - left) / 2;
    if (cont[middle] == 0) {
      left = middle;
    } else {
      right = middle;
    }
  }
  return left;
}
