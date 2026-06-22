#include <iostream>
#include <vector>

#include "topology_sort.hpp"

int main() {
  int N;
  std::cin >> N;
  std::vector<int> temp(N);
  for (int i = 0; i < N; i++) {
    std::cin >> temp[i];
  }
  std::vector<int> res = topology_sort(N, temp);
  for (int i = 0; i < N; i++) {
    std::cout << res[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}