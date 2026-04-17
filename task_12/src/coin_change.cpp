#include "coin_change.h"

#include <algorithm>
#include <limits>

int GetMinimumCoinCount(const int sum, const std::vector<int>& coins) {
  constexpr int inf = std::numeric_limits<int>::max() / 2;
  std::vector<int> dp(sum + 1, inf);
  dp[0] = 0;

  for (int current_sum = 1; current_sum <= sum; ++current_sum) {
    for (const int coin : coins) {
      if (coin <= current_sum) {
        dp[current_sum] = std::min(dp[current_sum], dp[current_sum - coin] + 1);
      }
    }
  }

  return dp[sum] >= inf ? -1 : dp[sum];
}
