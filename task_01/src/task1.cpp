#include "task1.hpp"

#include <vector>

std::pair<int, int> func(const std::vector<int>& arr, int Summa) {
  if (arr.size() < 2) {
    return {-1, -1};
  }

  int left = 0;
  int right = arr.size() - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];

    if (sum == Summa) {
      return {arr[left], arr[right]};
    } else if (sum < Summa) {
      left++;
    } else {
      right--;
    }
  }

  return {-1, -1};
}