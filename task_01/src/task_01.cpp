#include "task_01.hpp"

std::vector<int> FindTwoNums(int target, const std::vector<int>& arr) {
  int left = 0;
  int right = arr.size() - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target) {
      return {arr[left], arr[right]};
    } else if (sum < target) {
      ++left;
    } else {
      --right;
    }
  }
  return {};
};