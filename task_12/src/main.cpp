#include <iostream>
#include <vector>

#include "coin_change.hpp"

int main() {
  int sum = 0;
  int count = 0;
  std::cin >> sum >> count;

  std::vector<int> coins(count);
  for (int& coin : coins) {
    std::cin >> coin;
  }

  std::cout << MinCoins(sum, coins);
}
