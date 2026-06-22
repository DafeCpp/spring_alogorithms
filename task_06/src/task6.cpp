#include "task6.hpp"

#include <vector>

using namespace std;

int func(int N, int K, const vector<int>& arr) {
  long long sum = 0;
  vector<int> q(N);
  int start = 0;
  int finish = 0;

  for (int i = 0; i < N; i++) {
    int window_start = i - K + 1;
    if (start < finish && q[start] < window_start) {
      start++;
    }

    while (start < finish && arr[q[finish - 1]] >= arr[i]) {
      finish--;
    }

    q[finish] = i;
    finish++;

    sum += arr[q[start]];
  }

  return sum;
}
