#include <vector>

using namespace std;

double get_min_cost(int K, vector<double> fish_cost) {
  vector<double> min_costs;
  int left = 0;
  for (int i = 0; i < fish_cost.size(); ++i) {
    if (i == 0) continue;  // min_costs.push_back(fish_cost[0]);

    if (fish_cost[i] <= fish_cost[i - 1])  // min_costs.back())
                                           // min_costs.push_back(fish_cost[i]);
      else min_costs.push_back(min_costs.back());
  }
}