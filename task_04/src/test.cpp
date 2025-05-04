
#include <gtest/gtest.h>

#include "EconomicCalculation.hpp"

TEST(FindFish, Simple) {
  std::vector<int> prices = {3, 5, 2, 4, 1, 3};
  int K = 3;
  int N = prices.size();
  auto result = OptimizeFishPurchases(prices, K, N);
  std::vector<int> expected = {0, 0, 1, 0, 2, 0};
  ASSERT_EQ(expected, result);
}

TEST(FindFish, SamePrice) {
  std::vector<int> prices = {2, 2, 2, 2, 2};
  int K = 2;
  int N = prices.size();
  auto result = OptimizeFishPurchases(prices, K, N);
  std::vector<int> expected = {2, 0, 2, 0, 1};
  ASSERT_EQ(expected, result);
}

TEST(FindFish, ImmediateConsumption) {
  std::vector<int> prices = {5, 4, 3, 2, 1};
  int K = 1;
  int N = prices.size();
  auto result = OptimizeFishPurchases(prices, K, N);
  std::vector<int> expected = {1, 1, 1, 1, 1};
  ASSERT_EQ(expected, result);
}

TEST(FindFish, OneBuy) {
  std::vector<int> prices = {5, 3, 4, 2, 6};
  int K = 10;
  int N = prices.size();
  auto result = OptimizeFishPurchases(prices, K, N);
  std::vector<int> expected = {0, 0, 0, 2, 0};
  ASSERT_EQ(expected, result);
}

TEST(FindFish, OneDay) {
  std::vector<int> prices = {3};
  int K = 5;
  int N = prices.size();
  auto result = OptimizeFishPurchases(prices, K, N);
  std::vector<int> expected = {1};
  ASSERT_EQ(expected, result);
}

TEST(FindFish, OptimizedBuy) {
  std::vector<int> prices = {5, 4, 3, 2, 1};
  int K = 3;
  int N = prices.size();
  auto result = OptimizeFishPurchases(prices, K, N);
  std::vector<int> expected = {0, 0, 1, 0, 1};
  ASSERT_EQ(expected, result);
}