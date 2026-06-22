#include <iostream>

#include "solution.hpp"

int main() {
  int S, N;
  if ((std::cin >> S >> N)) {
    std::vector<int> coins(N);
    for (int i = 0; i < N; i++) {
      std::cin >> coins[i];
    }

    std::cout << minCoins(S, coins) << "\n";
  }
  return 0;
}
