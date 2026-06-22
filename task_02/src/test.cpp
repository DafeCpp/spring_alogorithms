#include <gtest/gtest.h>

#include "find_one_after_zero.hpp"

TEST(FindOneAfterZeroBasic, MinimumSize) {
  ASSERT_EQ(FindOneAfterZero(2, {0, 1}), 0);
}

TEST(FindOneAfterZeroBasic, Example1) {
  ASSERT_EQ(FindOneAfterZero(5, {0, 0, 0, 1, 1}), 2);
}

TEST(FindOneAfterZeroBasic, Example2) {
  ASSERT_EQ(FindOneAfterZero(6, {0, 0, 0, 0, 0, 1}), 4);
}

TEST(FindOneAfterZeroBasic, Example3) {
  ASSERT_EQ(FindOneAfterZero(5, {0, 1, 1, 1, 1}), 0);
}

TEST(FindOneAfterZeroBasic, BoundaryInMiddle) {
  ASSERT_EQ(FindOneAfterZero(7, {0, 0, 0, 1, 1, 1, 1}), 2);
}

TEST(FindOneAfterZeroBasic, OneZeroBeforeBoundary) {
  ASSERT_EQ(FindOneAfterZero(4, {0, 1, 1, 1}), 0);
}

TEST(FindOneAfterZeroBasic, OneOneAfterBoundary) {
  ASSERT_EQ(FindOneAfterZero(4, {0, 0, 0, 1}), 2);
}

TEST(FindOneAfterZeroBasic, LongArray) {
  ASSERT_EQ(FindOneAfterZero(10, {0, 0, 0, 0, 0, 1, 1, 1, 1, 1}), 4);
}

TEST(FindOneAfterZeroBasic, BoundaryNearEnd) {
  ASSERT_EQ(FindOneAfterZero(8, {0, 0, 0, 0, 0, 0, 1, 1}), 5);
}

TEST(FindOneAfterZeroBasic, BoundaryNearStart) {
  ASSERT_EQ(FindOneAfterZero(8, {0, 1, 1, 1, 1, 1, 1, 1}), 0);
}

TEST(FindOneAfterZeroUnsorted, MultipleCorrectAnswers1) {
  int result = FindOneAfterZero(6, {0, 1, 0, 1, 0, 1});
  ASSERT_TRUE(result == 0 || result == 2 || result == 4);
}

TEST(FindOneAfterZeroUnsorted, MultipleCorrectAnswers2) {
  int result = FindOneAfterZero(7, {1, 0, 0, 1, 1, 0, 1});
  ASSERT_TRUE(result == 1 || result == 2 || result == 5);
}

TEST(FindOneAfterZeroUnsorted, MultipleCorrectAnswers3) {
  int result = FindOneAfterZero(8, {0, 0, 1, 0, 0, 1, 0, 1});
  ASSERT_TRUE(result == 1 || result == 4 || result == 6);
}