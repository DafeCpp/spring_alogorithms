#include <gtest/gtest.h>

#include <vector>

#include "find_days_to_warm.hpp"

TEST(DaysToWarmingTest, NormalCase) {
  std::vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
  EXPECT_EQ(DaysToWarming(input), expected);
}

TEST(DaysToWarmingTest, NeverWarmer) {
  std::vector<int> input = {5, 4, 3, 2, 1};
  std::vector<int> expected = {0, 0, 0, 0, 0};
  EXPECT_EQ(DaysToWarming(input), expected);
}

TEST(DaysToWarmingTest, AlwaysWarmer) {
  std::vector<int> input = {1, 2, 3, 4, 5};
  std::vector<int> expected = {1, 1, 1, 1, 0};
  EXPECT_EQ(DaysToWarming(input), expected);
}

TEST(DaysToWarmingTest, SameTemperatures) {
  std::vector<int> input = {10, 10, 10, 10};
  std::vector<int> expected = {0, 0, 0, 0};
  EXPECT_EQ(DaysToWarming(input), expected);
}

TEST(DaysToWarmingTest, SingleDay) {
  std::vector<int> input = {15};
  std::vector<int> expected = {0};
  EXPECT_EQ(DaysToWarming(input), expected);
}

TEST(DaysToWarmingTest, EmptyInput) {
  std::vector<int> input = {};
  std::vector<int> expected = {};
  EXPECT_EQ(DaysToWarming(input), expected);
}