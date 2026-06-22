#include "fish_cost.h"

#include <deque>

long long GetMinimumFishCost(const std::vector<int>& prices, int storage_days) {
  std::deque<int> candidate_indices;
  long long total_cost = 0;

  for (int day = 0; day < static_cast<int>(prices.size()); ++day) {
    while (!candidate_indices.empty() &&
           candidate_indices.front() < day - storage_days + 1) {
      candidate_indices.pop_front();
    }

    while (!candidate_indices.empty() &&
           prices[candidate_indices.back()] >= prices[day]) {
      candidate_indices.pop_back();
    }

    candidate_indices.push_back(day);
    total_cost += prices[candidate_indices.front()];
  }

  return total_cost;
}
