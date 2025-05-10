#include "fish_days.hpp"

std::vector<int> calculate_fish_days(int N, int K,
                                     const std::vector<double>& prices) {
  if (prices.size() == 0) {
    return {};
  }
  std::vector<double> relevant_prices(K);
  std::vector<int> purchases(N, 0);
  std::vector<int> actual_days(K);
  relevant_prices[0] = prices[0];
  actual_days[0] = 0;
  double min_price = relevant_prices[0];
  int min_price_day = 0;
  ++purchases[min_price_day];
  for (int i{1}; i < N; ++i) {
    relevant_prices[i % K] = prices[i];
    actual_days[i % K] = i;
    if (prices[i] <= min_price) {
      min_price = prices[i];
      min_price_day = i;
    } else if (min_price_day <= i - K) {
      min_price = relevant_prices[0];
      min_price_day = actual_days[0];
      for (int j{1}; j < K; ++j) {
        if (relevant_prices[j] <= min_price) {
          min_price = relevant_prices[j];
          min_price_day = actual_days[j];
        }
      }
    }
    ++purchases[min_price_day];
  }
  return purchases;
}
