#include <iostream>
#include <vector>

#include "transition.hpp"

int main() {
  int size = 0;
  std::cin >> size;

  std::vector<int> values(size);
  for (int& value : values) {
    std::cin >> value;
  }

  std::cout << FindZeroOneBoundary(values);
}
