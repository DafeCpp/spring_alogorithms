#include "daily_temperatures.hpp"

#include <vector>

std::vector<int> DaysUntilWarmerTemperature(
    const std::vector<int>& temperatures) {
  std::vector<int> result(temperatures.size(), 0);
  std::vector<int> stack;

  for (int index = 0; index < static_cast<int>(temperatures.size()); ++index) {
    while (!stack.empty() && temperatures[index] > temperatures[stack.back()]) {
      const int colder_day = stack.back();
      stack.pop_back();
      result[colder_day] = index - colder_day;
    }
    stack.push_back(index);
  }

  return result;
}
