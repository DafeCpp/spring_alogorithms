#include <iostream>

#include "tables.hpp"

int main() {
  std::size_t n, m, k;
  std::cin >> n >> m >> k;

  std::vector<std::vector<int>> table(n, std::vector<int>(m));
  for (std::size_t i{0}; i != n; ++i) {
    for (std::size_t j{0}; j != m; ++j) {
      int a;
      std::cin >> a;
      table[i][j] = a;
    }
  }

  std::vector<Request> requests(k);
  for (std::size_t i{0}; i != k; ++i) {
    std::size_t l, r;
    std::cin >> l >> r;
    requests[i] = Request{l, r};
  }

  TableAnalyzer table_analyzer(table);
  for (const auto& answer : table_analyzer.CheckRanges(requests)) {
    std::cout << answer << std::endl;
  }
}