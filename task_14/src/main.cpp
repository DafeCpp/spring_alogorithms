#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "nondecreasing_segment.h"

int main() {
  int row_count;
  int column_count;
  int query_count;
  std::cin >> row_count >> column_count >> query_count;

  std::vector<std::vector<int>> table(row_count,
                                      std::vector<int>(column_count));
  for (int row = 0; row < row_count; ++row) {
    for (int col = 0; col < column_count; ++col) {
      std::cin >> table[row][col];
    }
  }

  std::vector<std::pair<int, int>> queries(query_count);
  for (int i = 0; i < query_count; ++i) {
    std::cin >> queries[i].first >> queries[i].second;
  }

  const std::vector<std::string> answers =
      CanReachNonDecreasingSegment(table, queries);
  for (size_t i = 0; i < answers.size(); ++i) {
    if (i > 0) {
      std::cout << '\n';
    }
    std::cout << answers[i];
  }

  return 0;
}
