#include <iostream>

#include "non_decreasing_ranges.hpp"

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<std::vector<int>> table(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) std::cin >> table[i][j];

  std::vector<int> max_right_rows(n);
  max_right_rows = GetNonDecreasingRanges(table);

  for (int i = 0; i < k; ++i) {
    int left, right;
    std::cin >> left >> right;
    std::cout << IsThereNonDecreasingColumn(left, right, max_right_rows)
              << "\n";
  }
}