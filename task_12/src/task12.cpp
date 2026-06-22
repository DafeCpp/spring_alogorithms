#include "task12.hpp"

#include <algorithm>
#include <vector>

int func(int S, int N, std::vector<int> arr) {
  std::sort(arr.begin(), arr.end());
  std::vector<int> dp(S + 1, S + 2);
  dp[0] = 0;
  for (int i = 1; i <= S; ++i) {
    for (int coin : arr) {
      if (i >= coin) dp[i] = std::min(dp[i], dp[i - coin] + 1);
    }
  }
  if (dp[S] == S + 2) return -1;
  return dp[S];
}