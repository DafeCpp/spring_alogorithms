
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(DailyTemperaturesTest, HandlesProblemExample) {
  EXPECT_EQ(GetDaysUntilWarmer({73, 74, 75, 71, 69, 72, 76, 73}),
            (std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
}

TEST(DailyTemperaturesTest, HandlesIncreasingTemperatures) {
  EXPECT_EQ(GetDaysUntilWarmer({30, 40, 50, 60}),
            (std::vector<int>{1, 1, 1, 0}));
}

TEST(DailyTemperaturesTest, HandlesDecreasingTemperatures) {
  EXPECT_EQ(GetDaysUntilWarmer({60, 50, 40, 30}),
            (std::vector<int>{0, 0, 0, 0}));
}

TEST(DailyTemperaturesTest, HandlesEqualTemperatures) {
  EXPECT_EQ(GetDaysUntilWarmer({30, 30, 31, 31}),
            (std::vector<int>{2, 1, 0, 0}));
}

TEST(DailyTemperaturesTest, HandlesSingleDay) {
  EXPECT_EQ(GetDaysUntilWarmer({42}), (std::vector<int>{0}));
}
