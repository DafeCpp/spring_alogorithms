#include "coin_change.hpp"

#include <algorithm>
#include <limits>

int MinCoins(int sum, const std::vector<int>& coins) {
  const int infinity = std::numeric_limits<int>::max() / 2;
  std::vector<int> dp(sum + 1, infinity);
  dp[0] = 0;

  for (int current = 1; current <= sum; ++current) {
    for (int coin : coins) {
      if (coin <= current) {
        dp[current] = std::min(dp[current], dp[current - coin] + 1);
      }
    }
  }

  return dp[sum] == infinity ? -1 : dp[sum];
}
