#include <iostream>
#include <string>

#include "permutation_substring.hpp"

int main() {
  std::string text;
  std::string pattern;
  std::cin >> text >> pattern;
  std::cout << FindPermutationSubstring(text, pattern);
}
