#include "MinCoins.h"

#include <vector>

int MinCoins(int S, const std::vector<int>& coins) {
  const int INF = S + 1;
  std::vector<int> dp(S + 1, INF);

  dp[0] = 0;

  for (int i = 1; i <= S; ++i) {
    for (int coin : coins) {
      if (i >= coin && dp[i - coin] != INF) {
        dp[i] = std::min(dp[i], dp[i - coin] + 1);
      }
    }
  }
  if (dp[S] == INF) {
    return -1;
  } else {
    return dp[S];
  }
}