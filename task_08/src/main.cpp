#include <iostream>
#include <vector>

#include "order_statistic.hpp"

int main() {
  int n, K;
  std::cin >> n >> K;

  std::vector<int> array(n);

  for (int i = 0; i < n; ++i) std::cin >> array[i];

  int left{0}, right(n - 1);
  std::cout << OrderStatistic(array, K, left, right) << "\n";
}
