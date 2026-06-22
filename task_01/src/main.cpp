#include <iostream>
#include <vector>

#include "FindPair.h"

int main() {
  int S, N;
  if (!(std::cin >> S)) return 0;
  if (!(std::cin >> N)) return 0;

  std::vector<int> mass;
  mass.reserve(N);
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    mass.push_back(x);
  }
  std::vector<int> result = FindPair(S, mass);
  for (size_t i = 0; i < result.size(); ++i) {
    if (i) std::cout << ' ';
    std::cout << result[i];
  }
  std::cout << '\n';
  return 0;
}
