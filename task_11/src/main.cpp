#include <iostream>
#include <string>

#include "substring_search.hpp"

int main() {
  std::string string, substring;

  std::getline(std::cin, string);
  std::getline(std::cin, substring);

  std::cout << SubstringSearch(string, substring) << "\n";
}
