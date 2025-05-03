#include "heap.hpp"

#include <climits>
#include <vector>

std::vector<std::pair<int, int>> buyFishSimplified(
    const std::vector<int>& prices, int K) {
  std::vector<std::pair<int, int>> purchases;
  int N = prices.size();

  for (int i = 0; i < N;) {
    int min_price = INT_MAX;
    int best_day = i;
    int window_end = std::min(i + K, N);

    // Находим день с минимальной ценой в окне
    for (int j = i; j < window_end; j++) {
      if (prices[j] < min_price) {
        min_price = prices[j];
        best_day = j;
      }
    }

    // Вычисляем сколько дней можно покрыть этой покупкой
    int days_covered = std::min(K, N - best_day);
    purchases.emplace_back(best_day, days_covered);

    // Переходим к следующему непокрытому дню
    i = best_day + days_covered;
  }

  return purchases;
}