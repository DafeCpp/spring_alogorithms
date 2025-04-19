#include "days_before_hot.hpp"

std::vector<int> DaysBeforeHot(std::vector<double> temperatures) {
  std::vector<int> days_before_h(temperatures.size());
  std::stack<std::vector<double>> memory{};
  int size = temperatures.size() - 1;
  for (int i{size}; i >= 0; --i) {
    while (!(memory.empty()) and (memory.top()[0] <= temperatures[i])) {
      memory.pop();
    }
    if (memory.empty()) {
      days_before_h[i] = 0;
    } else {
      days_before_h[i] = memory.top()[1] - i;
    }
    std::vector<double> day{temperatures[i], static_cast<double>(i)};
    memory.push(day);
  }
  return days_before_h;
}