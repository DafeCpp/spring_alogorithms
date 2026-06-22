#include <iostream>

#include "task14.hpp"

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;

  int** table = new int*[n];
  for (int i = 0; i < n; i++) {
    table[i] = new int[m];
    for (int j = 0; j < m; j++) {
      std::cin >> table[i][j];
    }
  }

  TableChecker checker(n, m, table);

  for (int q = 0; q < k; q++) {
    int l, r;
    std::cin >> l >> r;

    if (checker.check(l, r)) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }

  for (int i = 0; i < n; i++) {
    delete[] table[i];
  }
  delete[] table;

  return 0;
}