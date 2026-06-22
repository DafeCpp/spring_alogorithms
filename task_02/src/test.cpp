#include <gtest/gtest.h>

#include "transition.hpp"

TEST(ZeroOneBoundary, FindsMinimalCase) {
  EXPECT_EQ(FindZeroOneBoundary({0, 1}), 0);
}

TEST(ZeroOneBoundary, FindsMiddleCase) {
  EXPECT_EQ(FindZeroOneBoundary({0, 0, 0, 1, 1}), 2);
}

TEST(ZeroOneBoundary, FindsLateCase) {
  EXPECT_EQ(FindZeroOneBoundary({0, 0, 0, 0, 0, 1}), 4);
}
