#include <iostream>
#include <iterator>

#include "order_statistic.hpp"

int main() {
  std::size_t N, K;
  std::cin >> N >> K;
  std::vector<int> vec(std::istream_iterator<int>(std::cin),
                       std::istream_iterator<int>());

  std::cout << OrderStatistic(N, K, vec) << std::endl;
}
