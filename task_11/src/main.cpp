#include <iostream>
#include <string>

#include "substring_search.hpp"

int main() {
  std::string text, substring;

  std::getline(std::cin, text);
  std::getline(std::cin, substring);

  std::cout << SubstringSearch(text, substring) << "\n";
}
