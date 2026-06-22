#include "task14.hpp"

TableChecker::TableChecker(int rows, int cols, int** table) : n(rows), m(cols) {
  good = new int*[n];
  for (int i = 0; i < n; i++) {
    good[i] = new int[m];
  }

  for (int j = 0; j < m; j++) {
    good[0][j] = 0;
    for (int i = 1; i < n; i++) {
      if (table[i][j] >= table[i - 1][j]) {
        good[i][j] = good[i - 1][j];
      } else {
        good[i][j] = i;
      }
    }
  }
}

TableChecker::~TableChecker() {
  for (int i = 0; i < n; i++) {
    delete[] good[i];
  }
  delete[] good;
}

bool TableChecker::check(int l, int r) {
  l--;
  r--;

  for (int j = 0; j < m; j++) {
    if (good[r][j] <= l) {
      return true;
    }
  }
  return false;
}