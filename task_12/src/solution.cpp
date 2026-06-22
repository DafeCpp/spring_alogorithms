#include "solution.hpp"

#include <algorithm>

int minCoins(int S, const std::vector<int> &coins) {
  if (S < 0) return -1;
  if (S == 0) return 0;
  int INF = S + 1;
  std::vector<int> sums(S + 1, INF);

  sums[0] = 0;

  for (int i = 1; i <= S; i++) {
    for (int coin : coins) {
      if (i - coin >= 0) {
        if (sums[i - coin] != INF) {
          sums[i] = std::min(sums[i], sums[i - coin] + 1);
        }
      }
    }
  }
  if (sums[S] == INF) return -1;
  return sums[S];
}