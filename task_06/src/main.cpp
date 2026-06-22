#include <iostream>
#include <vector>

#include "MinTotalCost.h"

int main() {
  int N, K;
  if (!(std::cin >> N >> K)) return 0;

  std::vector<int> costs;
  costs.reserve(N);
  for (int i = 0; i < N; ++i) {
    int p;
    std::cin >> p;
    costs.push_back(p);
  }

  long long ans = MinTotalCost(K, costs);
  std::cout << ans << '\n';
  return 0;
}
