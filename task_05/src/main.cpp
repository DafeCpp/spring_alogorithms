#include <iostream>

#include "topology_sort.hpp"

int main() {
  int length = 0;
  std::cin >> length;

  std::vector<int> arr(length);
  for (int i = 0; i < length; i++) {
    std::cin >> arr[i];
  }
  std::vector<int> result = DaysToTemp(arr);
  for (auto& x : result) {
    std::cout << x << " ";
  }
  return 0;
}
