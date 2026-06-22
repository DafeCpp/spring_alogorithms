#include "FindBoundaryIndex.h"

#include <vector>

int FindBoundaryIndex(const std::vector<int>& mass) {
  int left = 0;
  int right = (int)mass.size() - 1;
  int mid = (int)mass.size() - 1;

  while (right - left > 1) {
    mid = (right - left) / 2 + left;

    if (mass[mid] == 0)
      left = mid;
    else
      right = mid;
  }

  return left;
}