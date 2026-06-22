#include <gtest/gtest.h>

#include "solution.hpp"
TEST(CoinChangeTest, Basic) {
  std::vector<int> coins = {1, 2, 5, 10};
  ASSERT_EQ(3, minCoins(14, coins));
}
TEST(CoinChangeTest, Impossible) {
  std::vector<int> coins = {2};
  ASSERT_EQ(-1, minCoins(3, coins));
}
TEST(CoinChangeTest, GreedyFail) {
  std::vector<int> coins = {1, 3, 4};
  ASSERT_EQ(2, minCoins(6, coins));
}
TEST(CoinChangeTest, Zero) {
  std::vector<int> coins = {1, 5, 10};
  ASSERT_EQ(0, minCoins(0, coins));
}
