#include <iostream>
#include <vector>

#include "order_statistic.hpp"

int main() {
  int size = 0;
  int statistic = 0;
  std::cin >> size >> statistic;

  std::vector<int> values(size);
  for (int& value : values) {
    std::cin >> value;
  }

  std::cout << KthOrderStatistic(values, statistic);
}
