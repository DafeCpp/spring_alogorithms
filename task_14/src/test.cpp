#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "task14.hpp"

TEST(HaveOrdered, AllColumnsSorted) {
  int n = 3, m = 3, k = 1;
  std::vector<std::vector<int>> Table = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> queries = {{0, 2}};

  std::vector<std::string> expected = {"YES"};
  ASSERT_EQ(expected, have_ordered(n, m, k, Table, queries));
}

TEST(HaveOrdered, OneColumnSorted) {
  int n = 4, m = 3, k = 1;
  std::vector<std::vector<int>> Table = {
      {10, 5, 100}, {20, 2, 50}, {30, 20, 10}, {40, 1, 1}};
  std::vector<std::vector<int>> queries = {{0, 3}};

  std::vector<std::string> expected = {"YES"};
  ASSERT_EQ(expected, have_ordered(n, m, k, Table, queries));
}

TEST(HaveOrdered, MixedQueries) {
  int n = 3, m = 2, k = 2;
  std::vector<std::vector<int>> Table = {{5, 5}, {2, 10}, {1, 15}};

  std::vector<std::vector<int>> queries = {{0, 2}, {0, 1}};

  std::vector<std::vector<int>> custom_queries = {{0, 2}, {1, 0}};

  std::vector<std::vector<int>> strict_queries = {{0, 2}, {0, 1}};

  std::vector<std::vector<int>> BadTable = {{10}, {5}, {2}};
  std::vector<std::vector<int>> bad_queries = {{0, 2}};
  std::vector<std::string> expected_no = {"NO"};

  ASSERT_EQ(expected_no, have_ordered(3, 1, 1, BadTable, bad_queries));
}

TEST(HaveOrdered, SingleRowQuery) {
  int n = 3, m = 2, k = 1;
  std::vector<std::vector<int>> Table = {{10, 20}, {5, 4}, {1, 2}};
  std::vector<std::vector<int>> queries = {{1, 1}};

  std::vector<std::string> expected = {"YES"};
  ASSERT_EQ(expected, have_ordered(n, m, k, Table, queries));
}
