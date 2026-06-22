#include "nondecreasing_segment.h"

#include <algorithm>

std::vector<std::string> CanReachNonDecreasingSegment(
    const std::vector<std::vector<int>>& table,
    const std::vector<std::pair<int, int>>& queries) {
  const int row_count = static_cast<int>(table.size());
  const int column_count = static_cast<int>(table.front().size());

  std::vector<int> best_reach(row_count, 1);
  std::vector<int> current(column_count, 1);

  for (int row = 1; row < row_count; ++row) {
    for (int col = 0; col < column_count; ++col) {
      if (table[row - 1][col] <= table[row][col]) {
        current[col] += 1;
      } else {
        current[col] = 1;
      }
      best_reach[row] = std::max(best_reach[row], current[col]);
    }
  }

  std::vector<std::string> answers;
  answers.reserve(queries.size());
  for (const auto& [left, right] : queries) {
    answers.push_back(best_reach[right - 1] >= right - left + 1 ? "Yes" : "No");
  }

  return answers;
}
