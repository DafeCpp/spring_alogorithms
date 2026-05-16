#include <iostream>
#include <vector>

#include "topology_sort.hpp"

int main() {
  int days_count;
  std::cin >> days_count;

  std::vector<int> temperatures(days_count);
  for (int i = 0; i < days_count; ++i) {
    std::cin >> temperatures[i];
  }

  const std::vector<int> result = GetDaysUntilWarmer(temperatures);
  for (size_t i = 0; i < result.size(); ++i) {
    if (i > 0) {
      std::cout << ' ';
    }
    std::cout << result[i];
  }

  return 0;
}
