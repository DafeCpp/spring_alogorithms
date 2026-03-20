#include <gtest/gtest.h>

#include <vector>

#include "util.hpp"

TEST(FishTest, BasicExample) {
  std::vector<int> prices = {5, 3, 4, 2, 6, 1};
  int result = func(6, 3, prices);
  EXPECT_EQ(result, 16);
}

TEST(FishTest, BuyEveryDay) {
  std::vector<int> prices = {5, 3, 4, 2, 6, 1};
  int result = func(6, 0, prices);
  EXPECT_EQ(result, 21);
}

TEST(FishTest, BuyFirstDay) {
  std::vector<int> prices = {5, 10, 15, 20};
  int result = func(4, 10, prices);
  EXPECT_EQ(result, 20);
}

TEST(FishTest, DecreasingPrices) {
  std::vector<int> prices = {100, 80, 60, 40, 20};
  int result = func(5, 2, prices);
  EXPECT_EQ(result, 300);
}

TEST(FishTest, IncreasingPrices) {
  std::vector<int> prices = {20, 40, 60, 80, 100};
  int result = func(5, 2, prices);
  EXPECT_EQ(result, 160);
}
TEST(FishTest, SingleDay) {
  std::vector<int> prices = {42};
  int result = func(1, 5, prices);
  EXPECT_EQ(result, 42);
}
TEST(FishTest, AllSamePrices) {
  std::vector<int> prices = {7, 7, 7, 7, 7};
  int result = func(5, 2, prices);
  EXPECT_EQ(result, 35);  // 7*5 = 35
}

TEST(FishTest, EmptyArray) {
  std::vector<int> prices = {};
  int result = func(0, 3, prices);
  EXPECT_EQ(result, 0);
}