#include <iostream>
#include <vector>

#include "merge_sort.hpp"

int main() {
  int size = 0;
  std::cin >> size;

  std::vector<int> values(size);
  for (int& value : values) {
    std::cin >> value;
  }

  MergeSort(values);
  for (int index = 0; index < static_cast<int>(values.size()); ++index) {
    if (index > 0) {
      std::cout << ' ';
    }
    std::cout << values[index];
  }
}
