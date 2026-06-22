#include <vector>

int MinCoins(int sum, const std::vector<int>& coins) {
    if (sum == 0) return 0;
    std::vector<int> dp(sum + 1, -1);
    dp[0] = 0;
    for (int s = 1; s <= sum; ++s) {
        for (int c : coins) {
            if (s >= c && dp[s - c] != -1) {
                int ways = dp[s - c] + 1;
                if (dp[s] == -1 || ways < dp[s]) {
                    dp[s] = ways;
                }
            }
        }
    }
    return dp[sum];
}