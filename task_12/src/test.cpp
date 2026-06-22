#include <gtest/gtest.h>

#include "coin_exchange.hpp"

TEST(CoinExchangeBasic, Example1) {
  ASSERT_EQ(FindCoinsCount(14, {1, 2, 5, 10}), 3);
}

TEST(CoinExchangeBasic, Example2) {
  ASSERT_EQ(FindCoinsCount(19, {1, 2, 5, 10}), 4);
}

TEST(CoinExchangeBasic, Example3) { ASSERT_EQ(FindCoinsCount(3, {2}), -1); }

TEST(CoinExchangeBasic, SingleCoinExact) {
  ASSERT_EQ(FindCoinsCount(10, {10}), 1);
}

TEST(CoinExchangeBasic, SingleCoinMultipleTimes) {
  ASSERT_EQ(FindCoinsCount(20, {5}), 4);
}

TEST(CoinExchangeBasic, PreferLargeCoin) {
  ASSERT_EQ(FindCoinsCount(15, {1, 5, 10}), 2);
}

TEST(CoinExchangeBasic, UnsortedCoins) {
  ASSERT_EQ(FindCoinsCount(14, {10, 1, 5, 2}), 3);
}

TEST(CoinExchangeBasic, TwoCoinTypes) {
  ASSERT_EQ(FindCoinsCount(8, {3, 5}), 2);
}

TEST(CoinExchangeBasic, RepeatedUseOfCoin) {
  ASSERT_EQ(FindCoinsCount(12, {1, 6}), 2);
}

TEST(CoinExchangeBasic, LargeCoinIgnored) {
  ASSERT_EQ(FindCoinsCount(7, {1, 100}), 7);
}

TEST(CoinExchangeCorner, ZeroSum) {
  ASSERT_EQ(FindCoinsCount(0, {1, 2, 5}), 0);
}

TEST(CoinExchangeCorner, CoinGreaterThanSum) {
  ASSERT_EQ(FindCoinsCount(3, {5, 10}), -1);
}

TEST(CoinExchangeCorner, ImpossibleOddSum) {
  ASSERT_EQ(FindCoinsCount(7, {2, 4}), -1);
}

TEST(CoinExchangeCorner, ExactByOneCoin) {
  ASSERT_EQ(FindCoinsCount(999, {999}), 1);
}

TEST(CoinExchangeCorner, ManyWaysChooseBest) {
  ASSERT_EQ(FindCoinsCount(18, {1, 7, 10}), 3);
}

TEST(CoinExchangeCorner, DuplicateCoinValues) {
  ASSERT_EQ(FindCoinsCount(10, {1, 1, 5, 5}), 2);
}

TEST(CoinExchangeCorner, LargeTarget) {
  ASSERT_EQ(FindCoinsCount(100, {1, 10, 25}), 4);
}

TEST(CoinExchangeCorner, AllCoinsLargerThanTarget) {
  ASSERT_EQ(FindCoinsCount(1, {2, 3, 4}), -1);
}