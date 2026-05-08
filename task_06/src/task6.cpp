#include "task6.hpp"

#include <algorithm>
#include <vector>

using namespace std;

int func(int N, int K, const vector<int>& arr) {
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    int start = max(0, i - K + 1);
    auto mini = min_element(arr.begin() + start, arr.begin() + i + 1);
    sum += *mini;
  }
  return sum;
}