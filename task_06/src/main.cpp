#include <iostream>
#include <vector>

#include "fish_cost.h"

int main() {
  int days_count;
  int storage_days;
  std::cin >> days_count >> storage_days;

  std::vector<int> prices(days_count);
  for (int i = 0; i < days_count; ++i) {
    std::cin >> prices[i];
  }

  std::cout << GetMinimumFishCost(prices, storage_days);
  return 0;
}
