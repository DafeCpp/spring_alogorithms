#include <gtest/gtest.h>
#include "coin_change.hpp"

TEST(CoinChangeTest, Example1) {
    std::vector<int> coins = {1, 2, 5, 10};
    ASSERT_EQ(minCoins(14, coins), 3);
}

TEST(CoinChangeTest, Example2) {
    std::vector<int> coins = {1, 2, 5, 10};
    ASSERT_EQ(minCoins(19, coins), 4);
}

TEST(CoinChangeTest, Example3) {
    std::vector<int> coins = {2};
    ASSERT_EQ(minCoins(3, coins), -1);
}

TEST(CoinChangeTest, ZeroSum) {
    std::vector<int> coins = {1, 2, 5};
    ASSERT_EQ(minCoins(0, coins), 0);
}

TEST(CoinChangeTest, SingleCoinExact) {
    std::vector<int> coins = {5};
    ASSERT_EQ(minCoins(5, coins), 1);
}

TEST(CoinChangeTest, SingleCoinNotExact) {
    std::vector<int> coins = {5};
    ASSERT_EQ(minCoins(3, coins), -1);
}

TEST(CoinChangeTest, GreedyFails) {
    std::vector<int> coins = {1, 3, 4};
    ASSERT_EQ(minCoins(6, coins), 2);  // 3 + 3, не 4 + 1 + 1
}

TEST(CoinChangeTest, LargeAmount) {
    std::vector<int> coins = {1, 2, 5, 10};
    ASSERT_EQ(minCoins(100, coins), 10);  // 10 монет по 10
}

TEST(CoinChangeTest, NoSolution) {
    std::vector<int> coins = {3, 5};
    ASSERT_EQ(minCoins(4, coins), -1);
}

TEST(CoinChangeTest, MultipleCoins) {
    std::vector<int> coins = {1, 2, 3, 4, 5};
    ASSERT_EQ(minCoins(7, coins), 2);  // 3 + 4
}

TEST(CoinChangeTest, LargeCoins) {
    std::vector<int> coins = {10, 20, 50};
    ASSERT_EQ(minCoins(30, coins), 2);  // 10 + 20
}

TEST(CoinChangeTest, ImpossibleWithLargeCoins) {
    std::vector<int> coins = {10, 20};
    ASSERT_EQ(minCoins(15, coins), -1);
}
