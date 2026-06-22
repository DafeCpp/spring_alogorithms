#include <iostream>
#include <vector>

#include "two_sum.hpp"

int main() {
  int target = 0;
  int size = 0;
  std::cin >> target >> size;

  std::vector<int> numbers(size);
  for (int& number : numbers) {
    std::cin >> number;
  }

  const auto answer = FindPairWithSum(numbers, target);
  if (answer.has_value()) {
    std::cout << answer->first << ' ' << answer->second;
  } else {
    std::cout << -1;
  }
}
