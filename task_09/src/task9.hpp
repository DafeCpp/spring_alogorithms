#ifndef TASK9_HPP
#define TASK9_HPP

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> PreprocessMaxReach(std::vector<std::vector<int>>& a) {
  int n = a.size();
  int m = a[0].size();

  std::vector<std::vector<int>> max_reach_col(m, std::vector<int>(n));
  for (int j = 0; j < m; ++j) {
    max_reach_col[j][n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
      if (a[i][j] <= a[i + 1][j]) {
        max_reach_col[j][i] = max_reach_col[j][i + 1];
      } else {
        max_reach_col[j][i] = i;
      }
    }
  }

  std::vector<int> max_reach_for_row(n);
  for (int i = 0; i < n; ++i) {
    max_reach_for_row[i] = i;
    for (int j = 0; j < m; ++j) {
      if (max_reach_col[j][i] > max_reach_for_row[i]) {
        max_reach_for_row[i] = max_reach_col[j][i];
      }
    }
  }

  for (int i = 1; i < n; ++i) {
    if (max_reach_for_row[i] < max_reach_for_row[i - 1]) {
      max_reach_for_row[i] = max_reach_for_row[i - 1];
    }
  }

  return max_reach_for_row;
}

bool CheckRangeSorted(const std::vector<int>& max_reach_for_row, int l, int r) {
  return max_reach_for_row[l] >= r;
}

#endif // TASK9_HPP