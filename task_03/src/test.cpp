
#include <gtest/gtest.h>

#include <vector>

#include "days_untill_warmer.hpp"

TEST(DaysUntilWarmerTest, IncreasingTemperatures) {
  std::vector<int> temps = {10, 20, 30, 40};
  std::vector<int> expected = {1, 1, 1, 0};
  EXPECT_EQ(DaysUntilWarmer(temps), expected);
}

TEST(DaysUntilWarmerTest, DecreasingTemperatures) {
  std::vector<int> temps = {40, 30, 20, 10};
  std::vector<int> expected = {0, 0, 0, 0};
  EXPECT_EQ(DaysUntilWarmer(temps), expected);
}

TEST(DaysUntilWarmerTest, MixedTemperatures) {
  std::vector<int> temps = {30, 40, 35, 42, 38, 33, 50};
  std::vector<int> expected = {1, 2, 1, 3, 2, 1, 0};
  EXPECT_EQ(DaysUntilWarmer(temps), expected);
}

TEST(DaysUntilWarmerTest, AllSameTemperatures) {
  std::vector<int> temps = {25, 25, 25, 25};
  std::vector<int> expected = {0, 0, 0, 0};
  EXPECT_EQ(DaysUntilWarmer(temps), expected);
}

TEST(DaysUntilWarmerTest, OneDayOnly) {
  std::vector<int> temps = {31};
  std::vector<int> expected = {0};
  EXPECT_EQ(DaysUntilWarmer(temps), expected);
}

TEST(DaysUntilWarmerTest, SpikeAtTheEnd) {
  std::vector<int> temps = {30, 25, 20, 35};
  std::vector<int> expected = {3, 2, 1, 0};
  EXPECT_EQ(DaysUntilWarmer(temps), expected);
}

TEST(DaysUntilWarmerTest, ValleyInMiddle) {
  std::vector<int> temps = {45, 30, 35, 20, 50};
  std::vector<int> expected = {4, 1, 2, 1, 0};
  EXPECT_EQ(DaysUntilWarmer(temps), expected);
}

TEST(DaysUntilWarmerTest, Empty) {
  std::vector<int> temps = {};
  EXPECT_THROW(DaysUntilWarmer(temps), std::runtime_error);
}
