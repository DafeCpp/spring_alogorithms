#include <iostream>
#include <vector>
#include "statistic.hpp"

int ReturnKth(int k, std::vector<int>& vec, int a, int b);

int main() {
  int n, k;
  std::cin >> n;

  std::vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i];
  }

  std::cin >> k;

  int result = ReturnKth(k, vec, 0, n - 1);
  std::cout << result << std::endl;

  return 0;
}