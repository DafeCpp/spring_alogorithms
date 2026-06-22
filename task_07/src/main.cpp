#include <iostream>
#include <sorting.hpp>

int main() {
  int length = 0;
  std::cin >> length;

  std::vector<int> arr(length);
  for (int i = 0; i < length; i++) {
    std::cin >> arr[i];
  }
  MergeSort(arr, 0, arr.size() - 1);
  for (auto& x : arr) {
    std::cout << x << " ";
  }

  return 0;
}
