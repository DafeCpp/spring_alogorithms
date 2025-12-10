#include <gtest/gtest.h>

#include "TableTask.hpp"

TEST(CanReachNonDecreasingSegment, SampleTest) {
  std::vector<std::vector<int>> table = {
      {1, 2, 3, 5}, {3, 1, 3, 2}, {4, 5, 2, 3}, {5, 5, 3, 2}, {4, 4, 3, 4}};

  std::vector<std::pair<int, int>> queries = {{1, 1}, {2, 5}, {4, 5},
                                              {3, 5}, {1, 3}, {1, 5}};

  auto result = TaskSolve(5, 4, 6, table, queries);
  std::vector<std::string> expected = {"Yes", "No", "Yes", "Yes", "Yes", "No"};

  ASSERT_EQ(result, expected);
}

TEST(CanReachNonDecreasingSegment, 1) {
  std::vector<std::vector<int>> table = {
      {1, 2, 3, 5}, {3, 1, 3, 2}, {4, 5, 2, 3}, {5, 5, 3, 2}, {4, 4, 3, 4}};
  std::vector<std::pair<int, int>> queries{{1, 1}, {2, 5}, {4, 5},
                                           {3, 5}, {1, 3}, {1, 5}};
  ASSERT_EQ(TaskSolve(5, 4, 6, table, queries),
            (std::vector<std::string>{"Yes", "No", "Yes", "Yes", "Yes", "No"}));
}

TEST(CanReachNonDecreasingSegment, 2) {
  std::vector<std::vector<int>> table = {{1, 1}};
  std::vector<std::pair<int, int>> queries = {{1, 1}};
  ASSERT_EQ(TaskSolve(1, 1, 1, table, queries),
            (std::vector<std::string>{"Yes"}));
}

TEST(CanReachNonDecreasingSegment, SingleElement) {
  std::vector<std::vector<int>> table = {{1}};
  std::vector<std::pair<int, int>> queries{{1, 1}};
  ASSERT_EQ(TaskSolve(1, 1, 1, table, queries),
            (std::vector<std::string>{"Yes"}));
}

TEST(CanReachNonDecreasingSegment, AllColumnsSorted) {
  std::vector<std::vector<int>> table = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
  std::vector<std::pair<int, int>> queries{{1, 3}, {2, 3}, {1, 2}};
  ASSERT_EQ(TaskSolve(3, 3, 3, table, queries),
            (std::vector<std::string>{"Yes", "Yes", "Yes"}));
}

TEST(CanReachNonDecreasingSegment, OneColumnSorted) {
  std::vector<std::vector<int>> table = {
      {5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5}};
  std::vector<std::pair<int, int>> queries{{1, 5}, {2, 4}, {3, 5}};
  ASSERT_EQ(TaskSolve(5, 2, 3, table, queries),
            (std::vector<std::string>{"Yes", "Yes", "Yes"}));
}