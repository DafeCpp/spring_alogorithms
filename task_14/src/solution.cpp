#include "solution.hpp"

#include <algorithm>

std::vector<std::string> Solve(
    int n, int m, const std::vector<std::vector<int>> &table,
    const std::vector<std::pair<int, int>> &queries) {
  std::vector<int> up(m, 0);
  std::vector<int> min_up(n, 0);

  for (int i = 0; i < n; i++) {
    int curr_best = i;
    for (int j = 0; j < m; j++) {
      if (!(i > 0 && table[i][j] >= table[i - 1][j])) up[j] = i;
      curr_best = std::min(curr_best, up[j]);
    }
    min_up[i] = curr_best;
  }

  std::vector<std::string> results;
  results.reserve(queries.size());
  for (const auto &q : queries) {
    int l = q.first - 1;
    int r = q.second - 1;
    if (min_up[r] <= l) {
      results.push_back("Yes");
    } else {
      results.push_back("No");
    }
  }
  return results;
}