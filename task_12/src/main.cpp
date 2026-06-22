#include <iostream>
#include <vector>

#include "coin_change.h"

int main() {
  int sum;
  int coin_count;
  std::cin >> sum >> coin_count;

  std::vector<int> coins(coin_count);
  for (int i = 0; i < coin_count; ++i) {
    std::cin >> coins[i];
  }

  std::cout << GetMinimumCoinCount(sum, coins);
  return 0;
}
