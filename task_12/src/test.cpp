#include <gtest/gtest.h>

#include "coin_change.hpp"

TEST(CoinChange, FindsMinimum) { EXPECT_EQ(MinCoins(14, {1, 2, 5, 10}), 3); }

TEST(CoinChange, HandlesImpossibleCase) { EXPECT_EQ(MinCoins(3, {2}), -1); }
