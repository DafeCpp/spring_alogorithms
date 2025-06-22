#include <gtest/gtest.h>

#include <vector>

#include "good_table.hpp"
// TEST(CanReachNonDecreasingSegment, 1) {
//   ASSERT_EQ(SolveFunction(5, 4, 6,
//                           std::vector<std::vector<int>>{{1, 2, 3, 5},
//                                                         {3, 1, 3, 2},
//                                                         {4, 5, 2, 3},
//                                                         {5, 5, 3, 2},
//                                                         {4, 4, 3, 4}},
//                           std::vector<std::pair<int, int>>{
//                               {1, 1}, {2, 5}, {4, 5}, {3, 5}, {1, 3}, {1,
//                               5}}),
//             (std::vector<std::string>{"Yes", "No", "Yes", "Yes", "Yes",
//             "No"}));
// }

// TEST(CanReachNonDecreasingSegment, 2) {
// ASSERT_EQ(SolveFunction(1, 1, 1, std::vector<std::vector<int>>{{1, 1}},
//                         std::vector<std::pair<int, int>>{{1, 1}}),
//           (std::vector<std::string>{"Yes"}));
// }

TEST(SortedTableCheckerTest, SingleColumnSorted) {
  std::vector<std::vector<int>> table = {{1}, {2}, {3}, {4}};
  SortedTableChecker checker(table);
  EXPECT_TRUE(checker.isSortedSegment(0, 3));
  EXPECT_TRUE(checker.isSortedSegment(1, 2));
  EXPECT_TRUE(checker.isSortedSegment(2, 3));
}

TEST(SortedTableCheckerTest, MultiColumnOneSorted) {
  std::vector<std::vector<int>> table = {{3, 2, 1}, {2, 2, 2}, {1, 2, 3}};
  SortedTableChecker checker(table);
  EXPECT_TRUE(checker.isSortedSegment(0, 2));
  EXPECT_TRUE(checker.isSortedSegment(1, 2));
  EXPECT_TRUE(checker.isSortedSegment(0, 1));
}

TEST(SortedTableCheckerTest, NoSortedColumns) {
  std::vector<std::vector<int>> table = {{3, 3, 3}, {2, 2, 2}, {1, 1, 1}};
  SortedTableChecker checker(table);
  EXPECT_FALSE(checker.isSortedSegment(0, 2));
  EXPECT_FALSE(checker.isSortedSegment(1, 2));
}

TEST(SortedTableCheckerTest, AllColumnsSorted) {
  std::vector<std::vector<int>> table = {
      {1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {4, 5, 6}};
  SortedTableChecker checker(table);
  EXPECT_TRUE(checker.isSortedSegment(0, 3));
  EXPECT_TRUE(checker.isSortedSegment(1, 3));
  EXPECT_TRUE(checker.isSortedSegment(2, 3));
}

TEST(SortedTableCheckerTest, EdgeCases) {
  std::vector<std::vector<int>> table = {{5}};
  SortedTableChecker checker(table);
  EXPECT_TRUE(checker.isSortedSegment(0, 0));

  std::vector<std::vector<int>> emptyTable;
  SortedTableChecker checkerEmpty(emptyTable);
  EXPECT_FALSE(checkerEmpty.isSortedSegment(0, 0));
}

TEST(SortedTableCheckerTest, OutOfBoundsQueries) {
  std::vector<std::vector<int>> table = {{1, 2}, {3, 4}};
  SortedTableChecker checker(table);
  EXPECT_FALSE(checker.isSortedSegment(-1, 1));
  EXPECT_FALSE(checker.isSortedSegment(0, 2));
  EXPECT_FALSE(checker.isSortedSegment(1, 0));
}