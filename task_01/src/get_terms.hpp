#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::pair<int, int> GetTerms(const std::vector<int>& array, int sum) {
  int n = array.size();

  if (n == 0 || n == 1) return std::pair(-1, -1);

  int l{0}, r{n - 1};

  int current_sum;
  while (l != r) {
    current_sum = array[l] + array[r];
    if (current_sum == sum) {
      return std::pair(array[l], array[r]);
    } else {
      if (current_sum > sum)
        --r;
      else
        ++l;
    }
  }

  return std::pair(-1, -1);
}