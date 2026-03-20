#pragma once
#include <algorithm>
#include <vector>

using namespace std;

int func(int N, int K, const vector<int>& vec) {
  if (N <= 0) return 0;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int start = max(0, i - K);
    int min_price = *min_element(vec.begin() + start, vec.begin() + i + 1);
    sum += min_price;
  }
  return sum;
}
