#include "util.hpp"

#include <vector>
using std::make_pair;

std::pair<int, int> func(int sum, const std::vector<int> &vec) {
  if (vec.size() < 2) return std::make_pair(0, 0);
  int l = 0;
  int r = vec.size() - 1;
  while (l < r) {
    if (vec[r] + vec[l] == sum) return std::make_pair(vec[l], vec[r]);
    if (vec[r] + vec[l] > sum)
      r -= 1;
    else
      l += 1;
  }
  return make_pair(-1, -1);
}
