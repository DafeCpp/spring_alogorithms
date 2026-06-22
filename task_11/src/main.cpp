#include <iostream>

#include "find_subsequence.hpp"

int main() {
  std::string sequence, subsequence;
  std::cin >> sequence >> subsequence;

  std::cout << FindSubsequence(sequence, subsequence) << std::endl;
}
