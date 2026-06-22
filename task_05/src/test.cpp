#include <gtest/gtest.h>

#include <vector>

#include "topology_sort.hpp"

TEST(Solution, Basic) {
  std::vector<int> input = {13, 12, 15, 11, 9, 12, 16};
  std::vector<int> expected = {2, 1, 4, 2, 1, 1, 0};
  ASSERT_EQ(DaysToTemp(input), expected);
}

TEST(Solution, Decreasing) {
  std::vector<int> input = {5, 4, 3, 2, 1};
  std::vector<int> expected = {0, 0, 0, 0, 0};
  ASSERT_EQ(DaysToTemp(input), expected);
}

TEST(Solution, Increasing) {
  std::vector<int> input = {1, 2, 3, 4, 5};
  std::vector<int> expected = {1, 1, 1, 1, 0};
  ASSERT_EQ(DaysToTemp(input), expected);
}

TEST(Solution, Duplicate) {
  std::vector<int> input = {2, 2, 2, 3, 2};
  std::vector<int> expected = {3, 2, 1, 0, 0};
  ASSERT_EQ(DaysToTemp(input), expected);
}

TEST(Solution, EdgeCases) {
  std::vector<int> input = {};
  std::vector<int> input2 = {10};
  std::vector<int> expected2 = {0};
  ASSERT_EQ(DaysToTemp(input), input);
  ASSERT_EQ(DaysToTemp(input2), expected2);
}