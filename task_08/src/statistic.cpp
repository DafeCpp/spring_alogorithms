#include "statistic.hpp"

#include <algorithm>
#include <vector>

int ReturnKth(int k, std::vector<int>& vec, int a, int b) {
  if (a == b) {
    return vec[a];
  }

  int pivot = vec[a + (b - a) / 2];
  int i = a;
  int j = b;

  while (i <= j) {
    while (vec[i] < pivot) {
      i++;
    }
    while (vec[j] > pivot) {
      j--;
    }
    if (i >= j) {
      break;
    }
    std::swap(vec[i], vec[j]);
    i++;
    j--;
  }

  int left_part = j - a + 1;

  if (k <= left_part) {
    return ReturnKth(k, vec, a, j);
  } else {
    return ReturnKth(k - left_part, vec, j + 1, b);
  }
}

int KthOrderStatistic(int k, std::vector<int> vec) {
  return ReturnKth(k, vec, 0, vec.size() - 1);
}