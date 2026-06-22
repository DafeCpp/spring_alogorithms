#include "coin_change.hpp"
#include <algorithm>
#include <climits>

int minCoins(int S, const std::vector<int>& coins) {
    if (S == 0) {
        return 0;
    }
    
    std::vector<int> dp(S + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= S; ++i) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[S] == INT_MAX ? -1 : dp[S];
}