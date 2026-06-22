#include <gtest/gtest.h>

#include "daily_temperatures.hpp"

TEST(DailyTemperatures, HandlesClassicCase) {
  EXPECT_EQ(DaysUntilWarmerTemperature({73, 74, 75, 71, 69, 72, 76, 73}),
            (std::vector<int>{1, 1, 4, 2, 1, 1, 0, 0}));
}

TEST(DailyTemperatures, HandlesDescendingCase) {
  EXPECT_EQ(DaysUntilWarmerTemperature({60, 50, 40, 30}),
            (std::vector<int>{0, 0, 0, 0}));
}
