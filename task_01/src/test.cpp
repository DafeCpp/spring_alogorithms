#include <gtest/gtest.h>

#include "two_sum.hpp"

TEST(TwoSum, FindsPair) {
  const auto answer = FindPairWithSum({2, 7, 11, 15}, 9);
  ASSERT_TRUE(answer.has_value());
  EXPECT_EQ(*answer, (std::pair<int, int>{2, 7}));
}

TEST(TwoSum, ReturnsNullWhenThereIsNoPair) {
  EXPECT_FALSE(FindPairWithSum({1, 2, 3}, 100).has_value());
}
