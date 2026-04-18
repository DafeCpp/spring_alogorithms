#include <vector>

int GetBorderIndex(std::vector<int> v) {
  int N = v.size();

  if (v[1] == 1) return 0;
  if (v[N - 2] == 0) return N - 2;

  int left = 0, right = N - 1;

  while (left + 1 < right) {
    int mid = (left + right) / 2;

    if (v[mid] == 1)
      right = mid;
    else
      left = mid;
  }
  return left;
}