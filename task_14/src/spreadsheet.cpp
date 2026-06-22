#include "spreadsheet.hpp"

#include <algorithm>

std::vector<std::string> AnswerSortedColumnQueries(
    const std::vector<std::vector<int>>& table,
    const std::vector<std::pair<int, int>>& queries) {
  const int rows = static_cast<int>(table.size());
  if (rows == 0) {
    return {};
  }
  const int columns = static_cast<int>(table[0].size());

  std::vector<int> start(columns, 1);
  std::vector<int> best(rows + 1, 1);
  for (int row = 2; row <= rows; ++row) {
    for (int column = 0; column < columns; ++column) {
      if (table[row - 2][column] > table[row - 1][column]) {
        start[column] = row;
      }
    }
    best[row] = *std::min_element(start.begin(), start.end());
  }

  std::vector<std::string> answers;
  answers.reserve(queries.size());
  for (const auto& [left, right] : queries) {
    answers.push_back(best[right] <= left ? "Yes" : "No");
  }
  return answers;
}
