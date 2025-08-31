
#include <gtest/gtest.h>

#include "NStatistic.hpp"

TEST(NStatistic, Simple) {
  std ::vector<int> data = {3, 1, 4, 1, 5};
  int n = 2;
  int ans = 3;
  ASSERT_EQ(NStatistic(data, n), ans);
}

TEST(NStatistic, OneElem) {
  std ::vector<int> data = {100};
  int n = 0;
  int ans = 100;
  ASSERT_EQ(NStatistic(data, n), ans);
}

TEST(NStatistic, SameElem) {
  std ::vector<int> data = {7, 7, 7, 7};
  int n = 2;
  int ans = 7;
  ASSERT_EQ(NStatistic(data, n), ans);
}

TEST(NStatistic, NegativeElem) {
  std ::vector<int> data = {-5, 0, -1, 3, -2};
  int n = 2;
  int ans = -1;
  ASSERT_EQ(NStatistic(data, n), ans);
}

TEST(NStatistic, BigN) {
  std ::vector<int> data = {1, 2, 3, 65, 4};
  int n = 100;
  EXPECT_THROW(NStatistic(data, n), std::invalid_argument);
}

TEST(NStatistic, Empty) {
  std ::vector<int> data = {};
  int n = 0;
  EXPECT_THROW(NStatistic(data, n), std::invalid_argument);
}
