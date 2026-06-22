#include <gtest/gtest.h>

#include <vector>

#include "./find_zero_one_pair.h"

namespace {

void ExpectValidTransition(const std::vector<int>& data, int i) {
  ASSERT_GE(i, 0);
  ASSERT_LT(i + 1, static_cast<int>(data.size()));
  EXPECT_EQ(data[i], 0);
  EXPECT_EQ(data[i + 1], 1);
}

}  // namespace

TEST(FindZeroOnePairTest, ThrowsIfEmpty) {
  EXPECT_THROW(FindZeroOnePair({}), std::invalid_argument);
}

TEST(FindZeroOnePairTest, ThrowsIfOneElement) {
  EXPECT_THROW(FindZeroOnePair({1}), std::invalid_argument);
}

TEST(FindZeroOnePairTest, ThrowsIfFirstElementNotZero) {
  EXPECT_THROW(FindZeroOnePair({1, 1, 1, 1}), std::invalid_argument);
}

TEST(FindZeroOnePairTest, ThrowsIfLastElementNotOne) {
  EXPECT_THROW(FindZeroOnePair({0, 0, 0, 0}), std::invalid_argument);
}

TEST(FindZeroOnePairTest, MinimalArray) {
  const std::vector<int> data = {0, 1};
  EXPECT_EQ(FindZeroOnePair(data), 0);
}

TEST(FindZeroOnePairTest, SortedReturnsValidTransition) {
  const std::vector<int> data = {0, 0, 1, 1};
  ExpectValidTransition(data, FindZeroOnePair(data));
}

TEST(FindZeroOnePairTest, SortedLateTransition) {
  const std::vector<int> data = {0, 0, 0, 0, 0, 1};
  ExpectValidTransition(data, FindZeroOnePair(data));
}

TEST(FindZeroOnePairTest, UnsortedAlternating) {
  const std::vector<int> data = {0, 1, 0, 1, 0, 1, 0, 1};
  ExpectValidTransition(data, FindZeroOnePair(data));
}

TEST(FindZeroOnePairTest, UnsortedOneInTheMiddle) {
  const std::vector<int> data = {0, 0, 0, 1, 0, 0, 0, 1};
  ExpectValidTransition(data, FindZeroOnePair(data));
}

TEST(FindZeroOnePairTest, UnsortedZeroInTheMiddle) {
  const std::vector<int> data = {0, 1, 1, 0, 1, 1, 1, 1};
  ExpectValidTransition(data, FindZeroOnePair(data));
}

TEST(FindZeroOnePairTest, UnsortedManyTransitions) {
  const std::vector<int> data = {0, 1, 0, 0, 1, 1, 0, 0, 0, 1};
  ExpectValidTransition(data, FindZeroOnePair(data));
}

TEST(FindZeroOnePairTest, LargeUnsortedRandomShape) {
  const std::vector<int> data = {0, 0, 1, 0, 1, 1, 0, 1, 0, 0,
                                 1, 1, 1, 0, 0, 1, 0, 0, 0, 1};
  ExpectValidTransition(data, FindZeroOnePair(data));
}
