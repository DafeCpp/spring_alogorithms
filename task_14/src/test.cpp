#include <gtest/gtest.h>

#include <vector>

#include "CanReachNonDecreasingSegment.h"

TEST(CanReachNonDecreasingSegment, Example) {
  std::vector<std::vector<int>> matrix = {
      {1, 2, 3, 5}, {3, 1, 3, 2}, {4, 5, 2, 3}, {5, 5, 3, 2}, {4, 4, 3, 4}};
  std::vector<std::pair<int, int>> queries = {{1, 1}, {2, 5}, {4, 5},
                                              {3, 5}, {1, 3}, {1, 5}};
  auto res = CanReachNonDecreasingSegment(matrix, queries);
  std::vector<bool> expected = {true, false, true, true, true, false};
  EXPECT_EQ(res, expected);
}

TEST(CanReachNonDecreasingSegment, AllEqual) {
  std::vector<std::vector<int>> matrix = {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}};
  std::vector<std::pair<int, int>> queries = {{1, 3}, {2, 3}};
  auto res = CanReachNonDecreasingSegment(matrix, queries);
  std::vector<bool> expected = {true, true};
  EXPECT_EQ(res, expected);
}

TEST(CanReachNonDecreasingSegment, NoSortedColumn) {
  std::vector<std::vector<int>> matrix = {{3, 3}, {1, 1}, {2, 2}};
  std::vector<std::pair<int, int>> queries = {{1, 3}};
  auto res = CanReachNonDecreasingSegment(matrix, queries);
  std::vector<bool> expected = {false};
  EXPECT_EQ(res, expected);
}

TEST(CanReachNonDecreasingSegment, SingleColumnSorted) {
  std::vector<std::vector<int>> matrix = {{1}, {3}, {5}, {7}};
  std::vector<std::pair<int, int>> queries = {{1, 4}, {2, 3}, {1, 2}};
  auto res = CanReachNonDecreasingSegment(matrix, queries);
  std::vector<bool> expected = {true, true, true};
  EXPECT_EQ(res, expected);
}

TEST(CanReachNonDecreasingSegment, SingleCell) {
  std::vector<std::vector<int>> matrix = {{5}};
  std::vector<std::pair<int, int>> queries = {{1, 1}};
  auto res = CanReachNonDecreasingSegment(matrix, queries);
  std::vector<bool> expected = {true};
  EXPECT_EQ(res, expected);
}
