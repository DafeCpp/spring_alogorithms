#include "MinTotalCost.h"

#include <deque>
#include <vector>

long long MinTotalCost(int K, const std::vector<int>& costs) {
  long long result = 0;
  std::deque<int> ind_min_costs;

  int N = (int)costs.size();

  for (int i = 0; i < N; i++) {
    if (!ind_min_costs.empty() && i - ind_min_costs.front() >= K)
      ind_min_costs.pop_front();

    while (!ind_min_costs.empty() && costs[i] <= costs[ind_min_costs.back()]) {
      ind_min_costs.pop_back();
    }

    ind_min_costs.push_back(i);
    // теперь в начале очереди гарантировано минимальная цена на рыбу для i-того
    // дня
    result += costs[ind_min_costs.front()];
  }
  return result;
}