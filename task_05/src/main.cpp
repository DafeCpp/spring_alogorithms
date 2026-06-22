#include <iostream>
#include <iterator>

#include "topology_sort.hpp"

int main() {
  std::size_t n_days;
  std::cin >> n_days;
  std::vector<int> temperature_data;
  for (std::size_t i{0}; i != n_days; ++i) {
    int temp;
    std::cin >> temp;
    temperature_data.push_back(temp);
  }
  auto result = TopologySort(n_days, temperature_data);
  for (auto elem : result) {
    std::cout << elem << ' ';
  }
}
