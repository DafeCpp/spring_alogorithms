#include "topology_sort.hpp"

std::vector<int> GetDaysUntilWarmer(const std::vector<int>& temperatures) {
  std::vector<int> result(temperatures.size(), 0);
  std::vector<int> stack_indices;

  for (int i = 0; i < static_cast<int>(temperatures.size()); ++i) {
    while (!stack_indices.empty() &&
           temperatures[i] > temperatures[stack_indices.back()]) {
      const int previous_index = stack_indices.back();
      stack_indices.pop_back();
      result[previous_index] = i - previous_index;
    }
    stack_indices.push_back(i);
  }

  return result;
}
