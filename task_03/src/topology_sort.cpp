#include "topology_sort.hpp"

std::vector<int> heater_days(std::vector<int>& temperatures) {
  int n = temperatures.size();
  std::vector<int> result(n, 0);
  std::stack<int> s;

  for (int i = 0; i < n; ++i) {
    while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
      int prev_index = s.top();
      s.pop();
      result[prev_index] = i - prev_index;
    }
    s.push(i);
  }

  return result;
}
