#include "task_01.h"

std::pair<int, int> FindValues(const int S, const int N,
                               const std::vector<int>& A) {
  int left = 0;
  int right = N - 1;

  while (left < right) {
    if (A[left] + A[right] < S) {
      left++;
    } else if (A[left] + A[right] > S) {
      right--;
    } else {
      return {A[left], A[right]};
    }
  }

  return {-1, -1};
}
