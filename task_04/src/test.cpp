#include <gtest/gtest.h>
#include "task4.hpp"

#include <vector>

TEST(BuyFishTest, EmptyList) {
    std::vector<int> empty;
    auto result = BuyFish(empty, 3);
    EXPECT_TRUE(result.empty());
}

TEST(BuyFishTest, SingleDay) {
    std::vector<int> prices = {5};
    std::vector<int> expected = {1};
    auto result = BuyFish(prices, 2);
    EXPECT_EQ(result, expected);
}

TEST(BuyFishTest, AllSamePrices) {
    std::vector<int> prices = {2, 2, 2, 2};
    std::vector<int> expected = {2, 1, 1, 0};
    auto result = BuyFish(prices, 2);
    EXPECT_EQ(result, expected);
}

TEST(BuyFishTest, DecreasingPrices) {
    std::vector<int> prices = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 1, 1, 1, 1};
    auto result = BuyFish(prices, 2);
    EXPECT_EQ(result, expected);
}

TEST(BuyFishTest, YourCase) {
    std::vector<int> prices = {3, 2, 5, 4, 5, 3, 2};
    std::vector<int> expected = {1, 3, 0, 1, 0, 1, 1};
    auto result = BuyFish(prices, 3);
    EXPECT_EQ(result, expected);
}