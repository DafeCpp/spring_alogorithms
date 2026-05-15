#include <iostream>
#include <merge_sort.hpp>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> v;

  for (int i = 0; i < N; ++i) {
    int n;
    std::cin >> n;
    v.push_back(n);
  }
  std::vector<int> v_sorted = MergeSort(v);

  for (int i = 0; i < N; ++i) std::cout << v_sorted[i] << " ";
}
