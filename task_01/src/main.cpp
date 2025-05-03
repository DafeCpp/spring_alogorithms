#include <iostream>
#include <vector>

#include "two_numbers.h"

int main() {
  int target;
  std::cout << "Enter the number:";
  std::cin >> target;

  int len;
  std::cout << "Enter the size of an array:";
  std::cin >> len;
  std::cout << "\n";

  std::vector<int> numbers(len);
  std::cout << "Enter the array:";
  for (int i{0}; i < len; ++i) std::cin >> numbers[i];

  FindSum(numbers, len, target);
}
