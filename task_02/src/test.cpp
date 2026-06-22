#include <gtest/gtest.h>

#include <vector>

#include "task2.hpp"

TEST(BoundaryTest, MinimalArray) {
  std::vector<int> arr = {0, 1};
  EXPECT_EQ(findBoundary(arr), 0);
}

TEST(BoundaryTest, AllZerosThenAllOnes) {
  std::vector<int> arr = {0, 0, 0, 1, 1, 1};
  EXPECT_EQ(findBoundary(arr), 2);
}

TEST(BoundaryTest, TransitionAtStart) {
  std::vector<int> arr = {0, 1, 1, 1, 1};
  EXPECT_EQ(findBoundary(arr), 0);
}

TEST(BoundaryTest, TransitionAtEnd) {
  std::vector<int> arr = {0, 0, 0, 0, 0, 1};
  EXPECT_EQ(findBoundary(arr), 4);
}

TEST(BoundaryTest, LargeArray) {
  std::vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  EXPECT_EQ(findBoundary(arr), 9);
}