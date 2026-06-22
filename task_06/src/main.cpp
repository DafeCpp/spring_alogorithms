#include <iostream>
#include <vector>

#include "task6.hpp"

int main() {
  int N, K;
  std::cin >> N >> K;

  std::vector<int> prices(N);
  for (int i = 0; i < N; i++) {
    std::cin >> prices[i];
  }

  std::cout << func(N, K, prices) << std::endl;

  return 0;
}