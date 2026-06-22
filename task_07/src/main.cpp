#include <iostream>
#include <vector>

#include "merge_sort.hpp"

int main() {
  int N;
  std::cin >> N;
  std::vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }
  std::vector<int> sorted_arr = MergeSort(arr);
  for (int i = 0; i < N; i++) {
    std::cout << sorted_arr[i] << " ";
  }
  return 0;
}
