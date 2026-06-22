#include "two_sum.hpp"

std::optional<std::pair<int, int>> FindPairWithSum(
    const std::vector<int>& numbers, int target) {
  int left = 0;
  int right = static_cast<int>(numbers.size()) - 1;

  while (left < right) {
    const long long sum =
        static_cast<long long>(numbers[left]) + numbers[right];
    if (sum == target) {
      return std::pair<int, int>{numbers[left], numbers[right]};
    }
    if (sum < target) {
      ++left;
    } else {
      --right;
    }
  }

  return std::nullopt;
}
