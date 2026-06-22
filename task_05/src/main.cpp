#include <iostream>
#include <vector>

#include "daily_temperatures.hpp"

int main() {
  int size = 0;
  std::cin >> size;

  std::vector<int> temperatures(size);
  for (int& temperature : temperatures) {
    std::cin >> temperature;
  }

  const auto answer = DaysUntilWarmerTemperature(temperatures);
  for (int index = 0; index < static_cast<int>(answer.size()); ++index) {
    if (index > 0) {
      std::cout << ' ';
    }
    std::cout << answer[index];
  }
}
