#include "task.hpp"

#include <stdexcept>

std::vector<bool> IsThereSortedColumns(
    const std::vector<std::vector<int>>& matrix,
    const std::vector<std::pair<size_t, size_t>>& l_and_r) {
  std::vector<std::vector<int>> prefixes_from_bools{BuildPrefixes(matrix)};
  std::vector<bool> ans{};
  for (auto pair : l_and_r) {
    size_t l = pair.first;
    size_t r = pair.second;
    if (l >= matrix.size() || r >= matrix.size() || l > r) {
      throw std::runtime_error("l or r is wrong");
    }
    if (l == r) {
      ans.push_back(true);
      continue;
    }
    bool is_found{false};
    for (int j{0}; j < matrix[0].size(); ++j) {
      if (prefixes_from_bools[r][j] - prefixes_from_bools[l][j] ==
          static_cast<int>(r - l)) {
        is_found = true;
        break;
      }
    }
    ans.push_back(is_found);
  }
  return ans;
}

std::vector<std::vector<int>> BuildPrefixes(
    const std::vector<std::vector<int>>& matrix) {
  if (matrix.size() == 0) {
    throw std::runtime_error("empty matrix");
  }
  size_t columns_num = matrix[0].size();
  for (int i{0}; i < matrix.size(); ++i) {
    if (matrix[i].size() != columns_num) {
      throw std::runtime_error("rows should have same size");
    }
  }
  std::vector<std::vector<int>> p(matrix.size(),
                                  std::vector<int>(columns_num, 0));
  for (int i{1}; i < matrix.size(); ++i) {
    for (int j{0}; j < columns_num; ++j) {
      p[i][j] = p[i - 1][j] + (matrix[i - 1][j] <= matrix[i][j] ? 1 : 0);
    }
  }
  return p;
}
