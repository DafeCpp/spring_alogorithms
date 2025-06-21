#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

class SortedTableChecker {
  int n, m;
  std::vector<std::vector<int>> a;
  std::vector<int> maxReachForRow;

 public:
  SortedTableChecker(const std::vector<std::vector<int>>& table) : a(table) {
    n = (int)a.size();
    m = n > 0 ? (int)a[0].size() : 0;
    preprocess();
  }

  void preprocess() {
    if (n == 0 || m == 0) return;

    std::vector<std::vector<int>> maxReachCol(m, std::vector<int>(n));

    for (int j = 0; j < m; j++) {
      maxReachCol[j][n - 1] = n - 1;
      for (int i = n - 2; i >= 0; i--) {
        if (a[i][j] <= a[i + 1][j])
          maxReachCol[j][i] = maxReachCol[j][i + 1];
        else
          maxReachCol[j][i] = i;
      }
    }

    maxReachForRow.resize(n);
    for (int i = 0; i < n; i++) {
      int best = i;
      for (int j = 0; j < m; j++) {
        if (maxReachCol[j][i] > best) best = maxReachCol[j][i];
      }
      maxReachForRow[i] = best;
    }

    for (int i = 1; i < n; i++) {
      if (maxReachForRow[i] < maxReachForRow[i - 1])
        maxReachForRow[i] = maxReachForRow[i - 1];
    }
  }

  bool isSortedSegment(int l, int r) const {
    if (l < 0 || r >= n || l > r) return false;
    return maxReachForRow[l] >= r;
  }
};
