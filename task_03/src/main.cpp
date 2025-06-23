#include <iostream>
#include <stack>
#include <vector>

#include "topology_sort.hpp"

int main() {
  std::vector<int> data{0, 2, 4, -5, 12, 16, -1, -1, -5, 4};
  std::vector<int> res{heater_days(data)};
  for (int val : res) {
    std::cout << val << " ";
  }
  return 0;
}
