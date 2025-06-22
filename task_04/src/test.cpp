
#include <gtest/gtest.h>

#include <vector>

#include "buy_fish.hpp"

namespace {

int totalFishBought(const std::vector<int>& purchases) {
  int total = 0;
  for (int p : purchases) total += p;
  return total;
}

bool isValidSchedule(const std::vector<int>& purchases, int k) {
  int n = purchases.size();
  std::vector<int> stock(n + k, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < std::min(i + k, n); ++j) {
      stock[j] += purchases[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (stock[i] == 0) return false;
    stock[i]--;
  }
  return true;
}

}  // namespace

TEST(BuyFishTest, SimpleIncreasingPrices) {
  std::vector<int> prices = {1, 2, 3, 4, 5};
  int k = 2;
  auto result = buy_fish(prices, k);
  EXPECT_EQ(result.size(), prices.size());
  EXPECT_EQ(totalFishBought(result), prices.size());
  EXPECT_TRUE(isValidSchedule(result, k));
}

TEST(BuyFishTest, SimpleDecreasingPrices) {
  std::vector<int> prices = {5, 4, 3, 2, 1};
  int k = 3;
  auto result = buy_fish(prices, k);
  EXPECT_EQ(result.size(), prices.size());
  EXPECT_EQ(totalFishBought(result), prices.size());
  EXPECT_TRUE(isValidSchedule(result, k));
}

TEST(BuyFishTest, ConstantPrices) {
  std::vector<int> prices = {10, 10, 10, 10, 10};
  int k = 2;
  auto result = buy_fish(prices, k);
  EXPECT_EQ(result.size(), prices.size());
  EXPECT_EQ(totalFishBought(result), prices.size());
  EXPECT_TRUE(isValidSchedule(result, k));
}

TEST(BuyFishTest, OneDayShelfLife) {
  std::vector<int> prices = {3, 2, 4, 1, 5};
  int k = 1;
  auto result = buy_fish(prices, k);
  EXPECT_EQ(result.size(), prices.size());
  EXPECT_EQ(totalFishBought(result), prices.size());
  EXPECT_TRUE(isValidSchedule(result, k));
}

TEST(BuyFishTest, LargeKLongPlanning) {
  std::vector<int> prices = {9, 1, 2, 3, 4, 1, 10, 2, 3, 4};
  int k = 5;
  auto result = buy_fish(prices, k);
  EXPECT_EQ(result.size(), prices.size());
  EXPECT_EQ(totalFishBought(result), prices.size());
  EXPECT_TRUE(isValidSchedule(result, k));
}

TEST(BuyFishTest, AlwaysBuyOnePerDay) {
  std::vector<int> prices = {5, 4, 6, 7, 3};
  int k = 1;
  auto result = buy_fish(prices, k);
  EXPECT_EQ(result.size(), prices.size());
  for (int r : result) {
    EXPECT_EQ(r, 1);  // можно купить только на сегодня
  }
}
