#include "topology_sort.hpp"

#include <stack>

std::vector<int> TopologySort(const std::vector<int>& temperatures) {
  std::vector<int> result(temperatures.size(), 0);
  std::stack<std::pair<int, int>> s;

  for (int i{0}; i < temperatures.size(); ++i) {
    while (!s.empty() && temperatures[i] > s.top().first) {
      int prev_index = s.top().second;
      result[prev_index] = i - prev_index;
      s.pop();
    }
    s.push({temperatures[i], i});
  }

  return result;
}