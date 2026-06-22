#include <iostream>

#include "solution.hpp"

int main() {
  std::string digits;
  if (std::cin >> digits) {
    std::vector<std::string> combs = LetterCombinations(digits);

    for (size_t i = 0; i < combs.size(); i++) {
      std::cout << combs[i] << " ";
    }
  }
  return 0;
}
