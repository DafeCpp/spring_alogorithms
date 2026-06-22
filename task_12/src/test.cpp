#include <gtest/gtest.h>
#include "coin.hpp"

TEST(MinCoins, Simple) {
    std::vector<int> coins1 = {1, 2, 5, 10};
    ASSERT_EQ(MinCoins(14, coins1), 3);
}

TEST(MinCoins, Zero) {
    std::vector<int> coins = {5, 10};
    ASSERT_EQ(MinCoins(0, coins), 0);
}

TEST(MinCoins, Impossible) {
    std::vector<int> coins = {6, 7};
    ASSERT_EQ(MinCoins(5, coins), -1);
}

TEST(MinCoins, One) {
    std::vector<int> coins = {3};
    ASSERT_EQ(MinCoins(9, coins), 3);
}