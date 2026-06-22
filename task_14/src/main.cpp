#include "solution.hpp"

int main() {
  int n, m, k;
  if (std::cin >> n >> m >> k) {
    std::vector<std::vector<int>> table(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cin >> table[i][j];
      }
    }
    std::vector<std::pair<int, int>> queries(k);
    for (int i = 0; i < k; i++) {
      std::cin >> queries[i].first >> queries[i].second;
    }
    std::vector<std::string> results = Solve(n, m, table, queries);
    for (const auto& res : results) {
      std::cout << res << std::endl;
    }
  }
  return 0;
}