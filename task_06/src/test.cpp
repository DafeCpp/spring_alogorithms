#include <gtest/gtest.h>

#include "fish_cost.h"

TEST(FishCostTest, HandlesSingleDay) {
  EXPECT_EQ(GetMinimumFishCost({5}, 1), 5);
}

TEST(FishCostTest, HandlesNoStorage) {
  EXPECT_EQ(GetMinimumFishCost({5, 3, 4}, 1), 12);
}

TEST(FishCostTest, HandlesFullStorage) {
  EXPECT_EQ(GetMinimumFishCost({5, 3, 4}, 3), 11);
}

TEST(FishCostTest, HandlesSlidingWindowMinimums) {
  EXPECT_EQ(GetMinimumFishCost({3, 1, 5, 2, 4}, 2), 9);
}

TEST(FishCostTest, HandlesEqualPrices) {
  EXPECT_EQ(GetMinimumFishCost({4, 4, 4, 4, 4}, 3), 20);
}

TEST(FishCostTest, HandlesCheapestDayInsideWindow) {
  EXPECT_EQ(GetMinimumFishCost({2, 8, 1, 5}, 3), 6);
}
