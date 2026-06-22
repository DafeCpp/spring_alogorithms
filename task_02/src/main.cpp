#include <iostream>
#include <iterator>

#include "find_one_after_zero.hpp"

int main() {
  std::size_t size;
  std::cin >> size;
  std::vector<int> vec(std::istream_iterator<int>(std::cin),
                       std::istream_iterator<int>());

  std::cout << FindOneAfterZero(size, vec);
}
