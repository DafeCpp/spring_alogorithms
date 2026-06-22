#include <gtest/gtest.h>

#include <vector>

#include "task12.hpp"

TEST(LeastAmountCoins, StandardCase) {
  std::vector<int> coins{1, 3, 4};
  int S = 6;
  int N = coins.size();
  ASSERT_EQ(2, least_amount(S, N, coins));
}

TEST(LeastAmountCoins, SingleCoinMatch) {
  std::vector<int> coins{1, 2, 5, 10};
  int S = 10;
  int N = coins.size();
  ASSERT_EQ(1, least_amount(S, N, coins));
}

TEST(LeastAmountCoins, NoSolution) {
  std::vector<int> coins{2, 4, 6};
  int S = 7;
  int N = coins.size();
  ASSERT_EQ(-1, least_amount(S, N, coins));
}

TEST(LeastAmountCoins, ZeroSum) {
  std::vector<int> coins{1, 2, 5};
  int S = 0;
  int N = coins.size();
  ASSERT_EQ(0, least_amount(S, N, coins));
}

TEST(LeastAmountCoins, LargeCoins) {
  std::vector<int> coins{10, 20, 50};
  int S = 5;
  int N = coins.size();
  ASSERT_EQ(-1, least_amount(S, N, coins));
}
