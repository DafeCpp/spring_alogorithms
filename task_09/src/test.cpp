#include <gtest/gtest.h>

#include "task.hpp"

TEST(IsThereSortedColumns, Simple) {
  std::vector<std::vector<int>> matrix{{1, 0, 3}, {2, 2, 3}, {1, 0, 2}};
  std::vector<std::pair<size_t, size_t>> pairs{{0, 2}, {1, 1}, {0, 1}};
  std::vector<bool> ans{false, true, true};
  ASSERT_EQ(IsThereSortedColumns(matrix, pairs), ans);
}

TEST(IsThereSortedColumns, EmptyMatrix) {
  std::vector<std::vector<int>> matrix;
  std::vector<std::pair<size_t, size_t>> pairs{{0, 0}};
  EXPECT_THROW(IsThereSortedColumns(matrix, pairs), std::runtime_error);
}

TEST(IsThereSortedColumns, WrongRows) {
  std::vector<std::vector<int>> matrix{{1, 2, 3}, {8, 9}};
  std::vector<std::pair<size_t, size_t>> pairs{{0, 0}};
  EXPECT_THROW(IsThereSortedColumns(matrix, pairs), std::runtime_error);
}

TEST(IsThereSortedColumns, SingleRow) {
  std::vector<std::vector<int>> matrix{{1, 2, 3}};
  std::vector<std::pair<size_t, size_t>> pairs{{0, 0}};
  std::vector<bool> ans{true};
  ASSERT_EQ(IsThereSortedColumns(matrix, pairs), ans);
}

TEST(IsThereSortedColumns, OneColumnSorted) {
  std::vector<std::vector<int>> matrix{{5, 1, 3}, {6, 0, 2}, {7, 0, 4}};
  std::vector<std::pair<size_t, size_t>> pairs{{0, 2}};
  std::vector<bool> ans{true};
  ASSERT_EQ(IsThereSortedColumns(matrix, pairs), ans);
}

TEST(IsThereSortedColumns, NoSortedColumns) {
  std::vector<std::vector<int>> matrix{{3, 2, 7}, {2, 3, 5}, {1, 2, 0}};
  std::vector<std::pair<size_t, size_t>> pairs{{0, 2}, {2, 2}, {1, 2}};
  std::vector<bool> ans{false, true, false};
  ASSERT_EQ(IsThereSortedColumns(matrix, pairs), ans);
}

TEST(IsThereSortedColumns, InvalidRange) {
  std::vector<std::vector<int>> matrix{{1, 2}, {3, 4}};
  std::vector<std::pair<size_t, size_t>> pairs{{1, 0}};  // l > r
  EXPECT_THROW(IsThereSortedColumns(matrix, pairs), std::runtime_error);
}

TEST(IsThereSortedColumns, InvalidRange2) {
  std::vector<std::vector<int>> matrix{{1, 2}, {3, 4}};
  std::vector<std::pair<size_t, size_t>> pairs{{0, 2}};  // r >= matrix.size()
  EXPECT_THROW(IsThereSortedColumns(matrix, pairs), std::runtime_error);
}