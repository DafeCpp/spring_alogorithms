
#include <deque>
#include <solution.hpp>

long long CalcCost(int n, int k, const std::vector<int> &prices) {
  long long total_cost = 0;
  std::deque<int> dq;
  for (int i = 0; i < n; i++) {
    if (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
    while (!dq.empty() && prices[dq.back()] >= prices[i]) dq.pop_back();
    dq.push_back(i);
    total_cost += prices[dq.front()];
  }
  return total_cost;
}