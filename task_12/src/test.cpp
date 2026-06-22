#include <gtest/gtest.h>

#include "coin_change.h"

TEST(CoinChangeTest, HandlesExampleOne) {
  EXPECT_EQ(GetMinimumCoinCount(14, {1, 2, 5, 10}), 3);
}

TEST(CoinChangeTest, HandlesExampleTwo) {
  EXPECT_EQ(GetMinimumCoinCount(19, {1, 2, 5, 10}), 4);
}

TEST(CoinChangeTest, HandlesImpossibleCase) {
  EXPECT_EQ(GetMinimumCoinCount(3, {2}), -1);
}

TEST(CoinChangeTest, HandlesGreedyTrap) {
  EXPECT_EQ(GetMinimumCoinCount(6, {1, 3, 4}), 2);
}

TEST(CoinChangeTest, HandlesZeroSum) {
  EXPECT_EQ(GetMinimumCoinCount(0, {1, 5, 10}), 0);
}
