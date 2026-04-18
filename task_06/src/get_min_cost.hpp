#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

double GetMinCost(int K, std::vector<double> fish_cost) {
  std::deque<double> min_costs;
  double min_sum = 0;
  for (int i = 0; i < fish_cost.size(); ++i) {
    if (min_costs.size() >= K) {
      min_costs.pop_front();
    }
    if (min_costs.empty()) {
      min_costs.push_back(fish_cost[i]);
      min_sum += fish_cost[i];
      continue;
    }
    min_costs.push_back(std::min(fish_cost[i], min_costs.back()));
    min_sum += min_costs.back();
    // std::cout << min_sum << " ";
  }
  return min_sum;
}

/*
double GetMinCost(int K, std::vector<double> fish_cost) {
  std::vector<double> min_costs;
  int left = 0;
  for (int i = 0; i < fish_cost.size(); ++i) {
    if (i == 0) continue;  // min_costs.push_back(fish_cost[0]);

    if (fish_cost[i] <= fish_cost[i - 1])  // min_costs.back())
                                           // min_costs.push_back(fish_cost[i]);
      else min_costs.push_back(min_costs.back());
  }
}
  */