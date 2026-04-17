#include <iostream>
#include <string>

#include "permutation_substring.h"

int main() {
  std::string text;
  std::string pattern;
  std::cin >> text >> pattern;

  std::cout << FindPermutationSubstringStart(text, pattern);
  return 0;
}
