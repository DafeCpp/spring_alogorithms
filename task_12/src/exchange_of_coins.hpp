#include <algorithm>
#include <vector>

int MinNumberOfCoins(int sum, std::vector<int> denominations) {
  int n = denominations.size();

  if (sum < 0) return -1;

  std::vector<int> dp(
      sum +
      1);  // i-ый элемент - минимальное количество монет, нужное для суммы i
  dp[0] = 0;

  for (int i = 1; i < sum + 1; ++i) {
    dp[i] = 2e9;
    for (int coin : denominations) {
      if (coin <= 0) continue;  // берем только положительные номиналы
      if (i - coin >= 0) {
        dp[i] = std::min(dp[i], dp[i - coin] + 1);
      }
    }
  }
  if (dp[sum] < 2e9) return dp[sum];
  return -1;
}