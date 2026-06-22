#include <iostream>
#include <iterator>

#include "fish_cost.hpp"

int main() {
  std::size_t N, K;
  std::cin >> N >> K;
  std::vector<int> vec(std::istream_iterator<int>(std::cin),
                       std::istream_iterator<int>());

  std::cout << MinFishCost(N, K, vec) << std::endl;
}
