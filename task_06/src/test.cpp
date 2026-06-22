#include <gtest/gtest.h>

#include "fish_buyer.hpp"

TEST(FishBuyer, HandlesNoStorage) { EXPECT_EQ(MinFishCost({5, 3, 4}, 1), 12); }

TEST(FishBuyer, HandlesSlidingWindow) {
  EXPECT_EQ(MinFishCost({3, 1, 5, 2, 4}, 2), 9);
}
