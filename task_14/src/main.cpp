#include <iostream>
#include <vector>

#include "CanReachNonDecreasingSegment.h"

int main() {
  int n, m, k;
  if (!(std::cin >> n >> m >> k)) return 0;

  std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) std::cin >> matrix[i][j];
  }

  std::vector<std::pair<int, int>> queries;
  queries.reserve(k);
  for (int i = 0; i < k; ++i) {
    int l, r;
    std::cin >> l >> r;
    queries.emplace_back(l, r);
  }

  auto results = CanReachNonDecreasingSegment(matrix, queries);
  for (bool ok : results) std::cout << (ok ? "Yes" : "No") << '\n';
  return 0;
}