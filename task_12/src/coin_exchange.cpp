#include "coin_exchange.hpp"

int FindCoinsCount(unsigned int sum, const std::vector<int>& coins) {
  std::vector<int> sum_to_coins_count(sum + 1, -1);
  sum_to_coins_count[0] = 0;

  for (unsigned int i = 1; i <= sum; ++i) {
    int best = -1;

    for (int coin : coins) {
      int idx = static_cast<int>(i) - coin;

      if (idx < 0) continue;

      if (sum_to_coins_count[idx] == -1) continue;

      int candidate = sum_to_coins_count[idx] + 1;

      if (best == -1 || candidate < best) best = candidate;
    }

    sum_to_coins_count[i] = best;
  }

  return sum_to_coins_count[sum];
}