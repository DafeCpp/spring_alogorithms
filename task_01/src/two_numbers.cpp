#include "two_numbers.h"

#include <iostream>

void FindSum(std::vector<int>& numbers, int len, int target) {
  int left_r = 0;
  int right_r = len - 1;

  while (left_r < right_r) {
    int sum = numbers[left_r] + numbers[right_r];
    if (right_r - left_r == 0) std::cout << "There are no necessary numbers";
    if (sum == target) {
      std::cout << numbers[left_r] << "+" << numbers[right_r] << "=" << target;
      break;
    }
    if (sum < target)
      ++left_r;
    else
      --right_r;
  }
}
