#include <iostream>

#include "task7.hpp"

int main() {
  int n;
  std::cin >> n;

  std::vector<int> arr(n);
  for (int i = 0; i < n; i++) std::cin >> arr[i];
  heapSort(arr);

  for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
  std::cout << std::endl;

  return 0;
}