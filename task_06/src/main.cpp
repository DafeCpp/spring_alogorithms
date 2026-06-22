#include <iostream>

#include "solution.hpp"

int main() {
  int n, k;
  if (std::cin >> n >> k) {
    std::vector<int> prices(n);
    for (int i = 0; i < n; i++) {
      std::cin >> prices[i];
    }
    std::cout << CalcCost(n, k, prices) << std::endl;
  }
  return 0;
}