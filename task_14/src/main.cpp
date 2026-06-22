#include <iostream>
#include <utility>
#include <vector>

#include "spreadsheet.hpp"

int main() {
  int rows = 0;
  int columns = 0;
  int query_count = 0;
  std::cin >> rows >> columns >> query_count;

  std::vector<std::vector<int>> table(rows, std::vector<int>(columns));
  for (auto& row : table) {
    for (int& value : row) {
      std::cin >> value;
    }
  }

  std::vector<std::pair<int, int>> queries(query_count);
  for (auto& [left, right] : queries) {
    std::cin >> left >> right;
  }

  const auto answers = AnswerSortedColumnQueries(table, queries);
  for (const std::string& answer : answers) {
    std::cout << answer << '\n';
  }
}
