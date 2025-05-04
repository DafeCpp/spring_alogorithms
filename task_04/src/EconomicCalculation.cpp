#include "EconomicCalculation.hpp"

#include <algorithm>

std::vector<int> OptimizeFishPurchases(std::vector<int>& prices, int K, int N) {
  std::vector<int> purchases(N, 0);
  int CurrentDay = 0;

  while (CurrentDay < N) {
    int Border = std::min(CurrentDay + K, N);
    int BestDay = CurrentDay;

    for (int day = CurrentDay; day < Border; ++day) {
      if (prices[day] < prices[BestDay]) {
        BestDay = day;
      }
    }
    int FishNeeded = Border - BestDay;
    purchases[BestDay] += FishNeeded;
    CurrentDay = BestDay + FishNeeded;
  }
  return purchases;
}