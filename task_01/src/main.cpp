#include <iostream>
#include <iterator>

#include "find_sum.hpp"

int main() {
  int sum;
  std::size_t size;
  std::cin >> sum >> size;
  std::vector<int> vec(std::istream_iterator<int>(std::cin),
                       std::istream_iterator<int>());

  auto res = FindSumHash(sum, size, vec);
  if (res.find) {
    if (res.b < 0) {
      std::cout << res.a;
    } else {
      std::cout << res.a << ' ' << res.b;
    }
  } else {
    std::cout << -1 << std::endl;
  }
  return 0;
}
