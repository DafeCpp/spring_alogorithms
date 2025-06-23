#include "days_before_hot.hpp"

struct TemperatureWithDayIndex {
  double temperature;
  int day_index;
};

std::vector<int> DaysBeforeHot(std::vector<double> temperatures) {
  std::vector<int> days_before_hot(temperatures.size());
  std::stack<TemperatureWithDayIndex> hotter_temperatures{};
  int size = temperatures.size() - 1;
  for (int i{size}; i >= 0; --i) {
    while (!(hotter_temperatures.empty()) &&
           (hotter_temperatures.top().temperature <= temperatures[i])) {
      hotter_temperatures.pop();
    }
    if (hotter_temperatures.empty()) {
      days_before_hot[i] = 0;
    } else {
      days_before_hot[i] = hotter_temperatures.top().day_index - i;
    }
    TemperatureWithDayIndex day{temperatures[i], i};
    hotter_temperatures.push(day);
  }
  return days_before_hot;
}