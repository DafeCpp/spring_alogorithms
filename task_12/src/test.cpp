
#include <gtest/gtest.h>

#include <vector>

#include "MinCoins.h"

TEST(Func12, Example1) {
  std::vector<int> coins = {1, 2, 5, 10};
  ASSERT_EQ(MinCoins(14, coins), 3);
}

TEST(Func12, Example2) {
  std::vector<int> coins = {1, 2, 5, 10};
  ASSERT_EQ(MinCoins(19, coins), 4);
}

TEST(Func12, SingleCoin) {
  std::vector<int> coins = {7};
  ASSERT_EQ(MinCoins(7, coins), 1);
}

TEST(Func12, ZeroSum) {
  std::vector<int> coins = {1, 5, 10};
  ASSERT_EQ(MinCoins(0, coins), 0);
}

TEST(Func12, Impossible) {
  std::vector<int> coins = {2};
  ASSERT_EQ(MinCoins(3, coins), -1);
}

TEST(Func12, GreedyTrap) {
  std::vector<int> coins = {1, 3, 4};
  ASSERT_EQ(MinCoins(6, coins), 2);
}
