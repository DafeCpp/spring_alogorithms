#include "solution.hpp"

int main() {
  std::string s, p;
  if (std::cin >> s >> p) {
    std::cout << FindSubstring(s, p) << std::endl;
  }
}
