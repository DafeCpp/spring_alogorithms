#include <iostream>
#include <vector>

#include "fish_buyer.hpp"

int main() {
  int days = 0;
  int shelf_life = 0;
  std::cin >> days >> shelf_life;

  std::vector<int> prices(days);
  for (int& price : prices) {
    std::cin >> price;
  }

  std::cout << MinFishCost(prices, shelf_life);
}
