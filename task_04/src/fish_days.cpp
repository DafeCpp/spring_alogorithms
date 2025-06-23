#include "fish_days.hpp"

std::vector<int> calculate_fish_days(int N, int K,
                                     const std::vector<double>& prices) {
  if (prices.empty()) return {};

  std::vector<int> purchases(N, 0);
  int min_price_day = 0;
  double min_price = prices[0];
  ++purchases[0];

  for (int i = 1; i < N; ++i) {
    if (prices[i] <= min_price) {  // если новый минимум
      min_price = prices[i];
      min_price_day = i;
    } else if (min_price_day <= i - K) {  // если минимум устарел
      min_price = prices[i - K + 1];
      min_price_day = i - K + 1;
      for (int j = i - K + 2; j <= i;
           ++j) {  // пересчёт минимума в окне [i-K+1, i]
        if (prices[j] <= min_price) {
          min_price = prices[j];
          min_price_day = j;
        }
      }
    }
    ++purchases[min_price_day];
  }
  return purchases;
}