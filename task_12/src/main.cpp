#include <iostream>
#include <vector>

#include "MinCoins.h"

int main() {
  int S, N;
  if (!(std::cin >> S)) return 0;
  if (!(std::cin >> N)) return 0;
  std::vector<int> coins(N);
  for (int i = 0; i < N; ++i) std::cin >> coins[i];
  int res = MinCoins(S, coins);
  std::cout << res << '\n';
  return 0;
}
