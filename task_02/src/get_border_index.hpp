#include <vector>

int GetBorderIndex(const std::vector<int> &v) {
  int left = 0, right = v.size() - 1;

  while (left + 1 < right) {
    int mid = (left + right) / 2;

    if (v[mid] == 1)
      right = mid;
    else
      left = mid;
  }
  return left;
}