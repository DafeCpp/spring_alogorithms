#include <iostream>
#include <iterator>

#include "heap_sort.hpp"

int main() {
  int size;
  std::cin >> size;
  std::vector<int> vec(std::istream_iterator<int>(std::cin),
                       std::istream_iterator<int>());
  auto res = HeapSort(vec);
  for (auto elem : res) {
    std::cout << elem << ' ';
  }
  return 0;
}
