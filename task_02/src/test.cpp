#include <gtest/gtest.h>

#include <vector>

#include "./find_zero_one_pair.h"

TEST(FindZeroOnePairTest, ThrowsIfEmpty) {
  EXPECT_THROW(FindZeroOnePair({}), std::invalid_argument);
}

TEST(FindZeroOnePairTest, ThrowsIfOneElement) {
  EXPECT_THROW(FindZeroOnePair({1}), std::invalid_argument);
}

TEST(FindZeroOnePairTest, TrowsIfFirstElementNotZero) {
  EXPECT_THROW(FindZeroOnePair({1, 1, 1, 1}), std::invalid_argument);
}

TEST(FindZeroOnePairTest, ReturnsIndexOfFirstIndex) {
  const std::vector<int> data = {0, 1};
  EXPECT_EQ(FindZeroOnePair(data), 0);
}

TEST(FindZeroOnePairTest, ReturnsIndexOfFirstMatchingPair) {
  const std::vector<int> data = {0, 0, 1, 1};
  EXPECT_EQ(FindZeroOnePair(data), 1);
}

TEST(FindZeroOnePairTest, StopsAtLastMatch) {
  const std::vector<int> data = {0, 0, 0, 0, 0, 1};
  EXPECT_EQ(FindZeroOnePair(data), 4);
}
