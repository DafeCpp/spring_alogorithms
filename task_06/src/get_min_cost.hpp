#include <deque>
#include <vector>

double GetMinCost(int K, std::vector<double> fish_cost) {
  double sum = 0.0;
  std::deque<int> rising_costs;  // индексы с возрастающими ценами

  for (int i = 0; i < fish_cost.size(); ++i) {
    if (!rising_costs.empty() && rising_costs.front() < i - K + 1)
      rising_costs.pop_front();

    while (!rising_costs.empty() &&
           fish_cost[rising_costs.back()] > fish_cost[i]) {
      rising_costs.pop_back();
    }
    rising_costs.push_back(i);

    sum += fish_cost[rising_costs.front()];
  }

  return sum;
}