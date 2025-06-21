#include "task_01.hpp"

std::vector<int> find_two_nums(int target, std::vector<int> arr) {
  int left = 0;
  int right = arr.size() - 1;
  int sum = arr[right] + arr[left];
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