#include <iostream>

#include "./phone_combinations.h"

int main() {
  std::string digits;
  std::cin >> digits;

  const auto combinations = GetPhoneCombinations(digits);
  for (size_t i = 0; i < combinations.size(); ++i) {
    if (i > 0) {
      std::cout << ' ';
    }
    std::cout << combinations[i];
  }

  return 0;
}
