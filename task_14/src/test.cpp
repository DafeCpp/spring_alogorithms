#include <gtest/gtest.h>

#include <vector>

#include "tables.hpp"

TEST(TableAnalyzerBasic, SingleRow) {
  std::vector<std::vector<int>> table = {{42}};

  TableAnalyzer analyzer(table);

  ASSERT_EQ(analyzer.CheckRange({1, 1}), "Yes");
}

TEST(TableAnalyzerBasic, ExampleFromStatement) {
  std::vector<std::vector<int>> table = {
      {1, 2, 3, 5}, {3, 1, 3, 2}, {4, 5, 2, 3}, {5, 5, 3, 2}, {4, 4, 3, 4}};

  TableAnalyzer analyzer(table);

  ASSERT_EQ(analyzer.CheckRange({1, 1}), "Yes");
  ASSERT_EQ(analyzer.CheckRange({2, 5}), "No");
  ASSERT_EQ(analyzer.CheckRange({4, 5}), "Yes");
  ASSERT_EQ(analyzer.CheckRange({3, 5}), "Yes");
  ASSERT_EQ(analyzer.CheckRange({1, 3}), "Yes");
  ASSERT_EQ(analyzer.CheckRange({1, 5}), "No");
}

TEST(TableAnalyzerBasic, EntireColumnSorted) {
  std::vector<std::vector<int>> table = {{1, 10}, {2, 9}, {3, 8}, {4, 7}};

  TableAnalyzer analyzer(table);

  ASSERT_EQ(analyzer.CheckRange({1, 4}), "Yes");
  ASSERT_EQ(analyzer.CheckRange({2, 4}), "Yes");
}

TEST(TableAnalyzerBasic, NoLongSortedSegment) {
  std::vector<std::vector<int>> table = {{1, 5}, {3, 4}, {2, 6}};

  TableAnalyzer analyzer(table);

  ASSERT_EQ(analyzer.CheckRange({1, 3}), "No");
}

TEST(TableAnalyzerBasic, SortedInSecondColumn) {
  std::vector<std::vector<int>> table = {{5, 1}, {4, 2}, {3, 3}, {2, 4}};

  TableAnalyzer analyzer(table);

  ASSERT_EQ(analyzer.CheckRange({1, 4}), "Yes");
}

TEST(TableAnalyzerBasic, EqualValuesAllowed) {
  std::vector<std::vector<int>> table = {{1, 5}, {1, 5}, {1, 5}, {1, 5}};

  TableAnalyzer analyzer(table);

  ASSERT_EQ(analyzer.CheckRange({1, 4}), "Yes");
}

TEST(TableAnalyzerBasic, TwoRowsSorted) {
  std::vector<std::vector<int>> table = {{1, 10}, {2, 5}};

  TableAnalyzer analyzer(table);

  ASSERT_EQ(analyzer.CheckRange({1, 2}), "Yes");
}

TEST(TableAnalyzerBasic, TwoRowsNotSortedEverywhere) {
  std::vector<std::vector<int>> table = {{5, 1}, {4, 2}};

  TableAnalyzer analyzer(table);

  ASSERT_EQ(analyzer.CheckRange({1, 2}), "Yes");
}

TEST(TableAnalyzerBasic, MiddleSegmentOnly) {
  std::vector<std::vector<int>> table = {{5}, {1}, {2}, {3}, {0}};

  TableAnalyzer analyzer(table);

  ASSERT_EQ(analyzer.CheckRange({2, 4}), "Yes");
  ASSERT_EQ(analyzer.CheckRange({1, 5}), "No");
}

TEST(TableAnalyzerBasic, MultipleColumnsHelp) {
  std::vector<std::vector<int>> table = {{5, 1}, {4, 2}, {3, 3}, {4, 0}};

  TableAnalyzer analyzer(table);

  ASSERT_EQ(analyzer.CheckRange({1, 3}), "Yes");
  ASSERT_EQ(analyzer.CheckRange({2, 4}), "No");
}