#include <vector>

std::vector<int> GetNonDecreasingRanges(
    const std::vector<std::vector<int>>& table) {
  if (table.empty()) return std::vector<int>{};
  int n = table.size();
  int m = table[0].size();

  std::vector<std::vector<int>> max_right_by_columns(
      n, std::vector<int>(m, 0));  // максимальное значение
                                   // правой строки для каждого столбца
  for (int j = 0; j < m; ++j) max_right_by_columns[n - 1][j] = n - 1;

  std::vector<int> max_right_rows(
      n, 0);  // i-ый элемент - максимальное значение
              // правой строки из всех столбцов для i-ой строки

  for (int i = n - 2; i >= 0; --i) {
    int max_in_row = i;
    for (int j = 0; j < m; ++j) {
      if (table[i][j] <= table[i + 1][j])
        max_right_by_columns[i][j] = max_right_by_columns[i + 1][j];
      else
        max_right_by_columns[i][j] = i;
      max_in_row = std::max(max_in_row, max_right_by_columns[i][j]);
    }
    max_right_rows[i] = max_in_row;
  }
  return max_right_rows;
}