#include <gtest/gtest.h>

#include "find.hpp"

TEST(FindNums, Simple) {
  std ::vector<int> seq{1, 2, 3, 4, 5};
  std ::vector<int> ans{FindNums(5, seq)};
  ASSERT_EQ(5, ans[0] + ans[1]);
}

TEST(FindNums, Negative) {
  std ::vector<int> seq{-100, -10, -9, -8, -1};
  std ::vector<int> ans{FindNums(-9, seq)};
  ASSERT_EQ(-9, ans[0] + ans[1]);
}

TEST(FindNums, WithZeros) {
  std ::vector<int> seq{
      -15, 0, 0, 2, 8,
  };
  std ::vector<int> ans{FindNums(10, seq)};
  ASSERT_EQ(10, ans[0] + ans[1]);
}

TEST(FindNums, NoValue) {
  std ::vector<int> seq{0, 0, 2, 8, -15};
  EXPECT_THROW(FindNums(60, seq), NoSumNum);
}

TEST(FindNums, Empty) {
  std ::vector<int> seq(0);
  EXPECT_THROW(FindNums(60, seq), NoSumNum);
}