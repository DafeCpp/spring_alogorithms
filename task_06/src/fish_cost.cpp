#include "fish_cost.hpp"

#include <deque>

long long MinFishCost(std::size_t N, std::size_t K,
                      const std::vector<int>& prices) {
  std::deque<std::size_t> min_costs;
  long long answer = 0;

  for (std::size_t i = 0; i < N; ++i) {
    while (!min_costs.empty() && min_costs.front() + K <= i) {
      min_costs.pop_front();
    }

    while (!min_costs.empty() && prices[min_costs.back()] >= prices[i]) {
      min_costs.pop_back();
    }

    min_costs.push_back(i);

    answer += prices[min_costs.front()];
  }

  return answer;
}