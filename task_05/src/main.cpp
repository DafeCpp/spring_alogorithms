#include <iostream>
#include <vector>

#include "topology_sort.hpp"

int main() {
  int N;
  if (!(std::cin >> N)) return 0;

  std::vector<int> temps;
  temps.reserve(N);
  for (int i = 0; i < N; ++i) {
    int t;
    std::cin >> t;
    temps.push_back(t);
  }

  std::vector<int> res = DistanceToNextGreaterElement(temps);

  for (int i = 0; i < (int)res.size(); ++i) {
    if (i) std::cout << ' ';
    std::cout << res[i];
  }
  if (!res.empty()) std::cout << '\n';

  return 0;
}
