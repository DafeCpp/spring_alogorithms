#include <iostream>
#include <vector>

#include "get_min_cost.hpp"

int main() {
  int n;
  double K;
  std::cin >> n >> K;

  std::vector<double> costs(n);
  for (int i = 0; i < n; ++i) std::cin >> costs[i];

  std::cout << GetMinCost(K, costs) << "\n";
}
