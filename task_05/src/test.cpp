
#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(DailyTemperaturesTest, HandlesProblemExample) {
  ASSERT_EQ(daysUntilWarmer({73, 74, 75, 71, 69, 72, 76, 73}),
            (std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
}

TEST(DailyTemperaturesTest, HandlesIncreasingTemperatures) {
  ASSERT_EQ(daysUntilWarmer({30, 40, 50, 60}),
            (std::vector<int>{1, 1, 1, 0}));
}

TEST(DailyTemperaturesTest, HandlesDecreasingTemperatures) {
  ASSERT_EQ(daysUntilWarmer({60, 50, 40, 30}),
            (std::vector<int>{0, 0, 0, 0}));
}

TEST(DailyTemperaturesTest, HandlesEqualTemperatures) {
  ASSERT_EQ(daysUntilWarmer({30, 30, 31, 31}),
            (std::vector<int>{2, 1, 0, 0}));
}

TEST(DailyTemperaturesTest, HandlesSingleDay) {
  ASSERT_EQ(daysUntilWarmer({42}), (std::vector<int>{0}));
}
