#include "topology_sort.hpp"

#include <stack>

std::vector<int> TopologySort(std::size_t N,
                              const std::vector<int>& temperature) {
  std::stack<int> stack;
  std::vector<int> result(N);
  std::size_t i{0};
  while (i < N) {
    if (stack.empty()) {
      stack.push(i);
      ++i;
      continue;
    }
    std::size_t idx = stack.top();
    if (temperature[idx] >= temperature[i]) {
      stack.push(i);
      ++i;
      continue;
    }
    if (temperature[idx] < temperature[i]) {
      result[idx] = i - idx;
      stack.pop();
      continue;
    }
  }
  return result;
}