#include <iostream>
#include <string>

#include "phone_combinations.hpp"

int main() {
  std::string digits;
  std::cin >> digits;

  const auto combinations = BuildPhoneCombinations(digits);
  for (int index = 0; index < static_cast<int>(combinations.size()); ++index) {
    if (index > 0) {
      std::cout << ' ';
    }
    std::cout << combinations[index];
  }
}
