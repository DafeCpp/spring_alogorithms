#include <iostream>
#include <vector>

#include "exchange_of_coins.hpp"

int main() {
  int sum;
  std::cin >> sum;

  int n;
  std::cin >> n;

  std::vector<int> denominations(n);
  for (int i = 0; i < n; ++i) std::cin >> denominations[i];

  std::cout << MinNumberOfCoins(sum, denominations) << "\n";
}
