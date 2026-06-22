#include <iostream>
#include <string>

#include "task3.hpp"

int main() {
  std::string s;
  std::cin >> s;

  std::vector<std::string> result = letterCombinations(s);

  for (size_t i = 0; i < result.size(); ++i) {
    std::cout << result[i];
    if (i < result.size() - 1) std::cout << " ";
  }
  std::cout << std::endl;

  return 0;
}