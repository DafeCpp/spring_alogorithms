#include <gtest/gtest.h>

#include <vector>

#include "task5.hpp"

TEST(DailyTemperatures, BaseExample) {
  std::vector<int> t = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
  ASSERT_EQ(dailyTemperatures(t), expected);
}

TEST(DailyTemperatures, AlwaysIncreasing) {
  std::vector<int> t = {30, 40, 50, 60};
  std::vector<int> expected = {1, 1, 1, 0};
  ASSERT_EQ(dailyTemperatures(t), expected);
}

TEST(DailyTemperatures, AlwaysDecreasing) {
  std::vector<int> t = {60, 50, 40, 30};
  std::vector<int> expected = {0, 0, 0, 0};
  ASSERT_EQ(dailyTemperatures(t), expected);
}

TEST(DailyTemperatures, SameTemperatures) {
  std::vector<int> t = {50, 50, 50, 50};
  std::vector<int> expected = {0, 0, 0, 0};
  ASSERT_EQ(dailyTemperatures(t), expected);
}

TEST(DailyTemperatures, SingleDay) {
  std::vector<int> t = {42};
  std::vector<int> expected = {0};
  ASSERT_EQ(dailyTemperatures(t), expected);
}
