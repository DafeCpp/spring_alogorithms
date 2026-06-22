#include "fish_buyer.hpp"

#include <deque>

long long MinFishCost(const std::vector<int>& prices, int shelf_life) {
  long long total = 0;
  std::deque<int> candidates;

  for (int day = 0; day < static_cast<int>(prices.size()); ++day) {
    while (!candidates.empty() && candidates.front() <= day - shelf_life) {
      candidates.pop_front();
    }
    while (!candidates.empty() && prices[candidates.back()] >= prices[day]) {
      candidates.pop_back();
    }
    candidates.push_back(day);
    total += prices[candidates.front()];
  }

  return total;
}
