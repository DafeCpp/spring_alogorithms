#include "find_days_to_warm.hpp"

#include <algorithm>
#include <stack>
#include <utility>
#include <vector>

std::vector<int> DaysToWarming(std::vector<int> temperature_list) {
  if (temperature_list.size() == 0) {
    return std::vector<int>{};
  }

  std::vector<int> days_to_warming;
  std::stack<std::pair<int, int>> decreasing_stack;

  int last_index{temperature_list.size() - 1};

  decreasing_stack.push(
      std::pair<int, int>(temperature_list[last_index], last_index));
  for (int i{last_index}; i >= 0; i--) {
    while (!decreasing_stack.empty() &&
           temperature_list[i] >= decreasing_stack.top().first) {
      decreasing_stack.pop();
    }
    if (decreasing_stack.empty()) {
      days_to_warming.push_back(0);
      decreasing_stack.push(std::pair<int, int>(temperature_list[i], i));
    } else {
      int previous_index = decreasing_stack.top().second;
      decreasing_stack.push(std::pair<int, int>(temperature_list[i], i));
      int current_index = decreasing_stack.top().second;
      days_to_warming.push_back(previous_index - current_index);
    }
  }
  std::reverse(days_to_warming.begin(), days_to_warming.end());
  return days_to_warming;
}