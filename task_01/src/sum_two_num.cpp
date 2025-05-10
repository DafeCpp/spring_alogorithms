#include "sum_two_num.h"

#include <iostream>

void FindSumTwoNum(std::vector<int>& vec, int len, int num) {
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = vec[left] + vec[right];
    if (right - left == 0) std::cout << "There are no necessary numbers";
    if (sum == num) {
      std::cout << vec[left] << "+" << vec[right] << "=" << num;
      break;
    }
    if (sum < num)
      ++left;
    else
      --right;
  }
}