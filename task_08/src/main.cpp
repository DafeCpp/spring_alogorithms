#include <iostream>
#include <vector>

#include "order_statistic.h"

int main() {
  int size;
  int order;
  std::cin >> size >> order;

  std::vector<int> values(size);
  for (int i = 0; i < size; ++i) {
    std::cin >> values[i];
  }

  std::cout << GetOrderStatistic(values, order);
  return 0;
}
