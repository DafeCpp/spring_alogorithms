#include <gtest/gtest.h>

#include "fish_cost.hpp"

TEST(FishBuyerBasic, Example1) { ASSERT_EQ(MinFishCost(1, 1, {5}), 5); }

TEST(FishBuyerBasic, Example2) { ASSERT_EQ(MinFishCost(3, 1, {5, 3, 4}), 12); }

TEST(FishBuyerBasic, Example3) { ASSERT_EQ(MinFishCost(3, 3, {5, 3, 4}), 11); }

TEST(FishBuyerBasic, IncreasingPrices) {
  ASSERT_EQ(MinFishCost(5, 2, {1, 2, 3, 4, 5}), 11);
  // 1 + 1 + 2 + 3 + 4
}

TEST(FishBuyerBasic, DecreasingPrices) {
  ASSERT_EQ(MinFishCost(5, 2, {5, 4, 3, 2, 1}), 15);
  // 5 + 4 + 3 + 2 + 1
}

TEST(FishBuyerBasic, ConstantPrices) {
  ASSERT_EQ(MinFishCost(6, 3, {7, 7, 7, 7, 7, 7}), 42);
}

TEST(FishBuyerBasic, SmallK) {
  ASSERT_EQ(MinFishCost(5, 1, {3, 1, 4, 1, 5}), 14);
  // каждый день только текущая цена
}

TEST(FishBuyerBasic, FullWindow) {
  ASSERT_EQ(MinFishCost(4, 4, {10, 1, 10, 1}), 13);
  // 10 + 1 + 1 + 1
}

TEST(FishBuyerBasic, RandomCase1) {
  ASSERT_EQ(MinFishCost(6, 3, {5, 1, 3, 2, 4, 1}), 11);
}

TEST(FishBuyerBasic, RandomCase2) {
  ASSERT_EQ(MinFishCost(7, 2, {2, 9, 1, 5, 6, 1, 2}), 13);
}

TEST(FishBuyerCorner, SingleDayLargeK) {
  ASSERT_EQ(MinFishCost(1, 10, {100}), 100);
}

TEST(FishBuyerCorner, KEqualsN) {
  ASSERT_EQ(MinFishCost(5, 5, {5, 4, 3, 2, 1}), 15);
  // 5 + 4 + 3 + 2 + 1
}

TEST(FishBuyerCorner, StrictlyIncreasingWindowEffect) {
  ASSERT_EQ(MinFishCost(6, 3, {1, 2, 3, 4, 5, 6}), 12);
}

TEST(FishBuyerCorner, StrictlyDecreasingWindowEffect) {
  ASSERT_EQ(MinFishCost(6, 3, {6, 5, 4, 3, 2, 1}), 21);
  // 6 + 5 + 4 + 3 + 2 + 1
}

TEST(FishBuyerCorner, KIsOneEdgeCase) {
  ASSERT_EQ(MinFishCost(4, 1, {10, 1, 10, 1}), 22);
}

TEST(FishBuyerCorner, LargeStableWindow) {
  ASSERT_EQ(MinFishCost(5, 10, {3, 1, 2, 1, 4}), 7);
  // 3 + 1 + 1 + 1 + 1
}