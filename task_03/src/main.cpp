#include <get_combinations.hpp>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string digits;
  getline(std::cin, digits);

  std::vector<std::string> result = GetCombinations(digits);

  for (std::string str : result) std::cout << str << " ";
}
