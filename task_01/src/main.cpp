#include <iostream>

#include "solution.hpp"

int main() {
  std::cout << (BinarySearchGEQ({1, 2, 3, 4, 5}, 1, 0, 4) == 0) << std::endl;
  std::cout << (BinarySearchGEQ({1, 2, 3, 4, 5}, 5, 0, 4) == 4)
            << std::endl;  // Stack []
}
