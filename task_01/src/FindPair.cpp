#include "FindPair.h"

#include <vector>

std::vector<int> FindPair(int S, const std::vector<int>& mass) {
  int right = 0;
  int left = (int)mass.size() - 1;
  std::vector<int> result = {-1};

  if (mass.size() < 2) return result;

  if (mass[right] > mass[left]) {  // в порядке убывания
    while (mass[right] + mass[left] != S) {
      if (right >= left) break;

      if (mass[right] + mass[left] < S)
        left--;
      else if (mass[right] + mass[left] > S)
        right++;
    }
  } else {  // в порядке возрастания

    while (mass[right] + mass[left] != S) {
      if (right >= left) break;

      if (mass[right] + mass[left] < S)
        right++;
      else if (mass[right] + mass[left] > S)
        left--;
    }
  }

  if (right < left && mass[right] + mass[left] == S)
    result = {std::min(mass[right], mass[left]),
              std::max(mass[right], mass[left])};

  return result;
}
