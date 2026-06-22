#include "CanReachNonDecreasingSegment.h"

#include <algorithm>
#include <utility>
#include <vector>

std::vector<bool> CanReachNonDecreasingSegment(
    const std::vector<std::vector<int>>& matrix,
    const std::vector<std::pair<int, int>>& queries) {
  if (matrix.empty() || matrix[0].empty()) return {};

  int n = matrix.size();
  int m = matrix[0].size();

  std::vector<int> col_start(m, 0);
  std::vector<int> min_start(n, 0);

  for (int i = 0; i < n; ++i) {
    int current_min_start = i;
    for (int j = 0; j < m; ++j) {
      if (i > 0 && matrix[i][j] < matrix[i - 1][j]) {
        col_start[j] = i;
      }
      current_min_start = std::min(current_min_start, col_start[j]);
    }
    min_start[i] = current_min_start;
  }

  std::vector<bool> results;
  results.reserve(queries.size());

  for (const std::pair<int, int>& query : queries) {
    int l = query.first - 1;
    int r = query.second - 1;

    results.push_back(min_start[r] <= l);
  }

  return results;
}