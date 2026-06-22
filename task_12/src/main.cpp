#include <iostream>
#include <iterator>

#include "coin_exchange.hpp"

int main() {
  std::size_t S, N;
  std::cin >> S >> N;
  std::vector<int> vec(std::istream_iterator<int>(std::cin),
                       std::istream_iterator<int>());
  std::cout << FindCoinsCount(S, vec) << std::endl;
}
