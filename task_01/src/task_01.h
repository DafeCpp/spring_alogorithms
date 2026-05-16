#pragma once
#include <utility>
#include <vector>

inline std::pair<int, int> FindValues(const int S, const int N,
                                      std::vector<int>& A) {
  int left = 0;
  int right = N - 1;
  int first_value = 0;

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