#include <gtest/gtest.h>

#include "find_sum.hpp"

TEST(FindSumHashBasic, NoSolution) {
  auto result = FindSumHash(100, 3, {1, 2, 3});

  ASSERT_FALSE(result.find);
}

TEST(FindSumHashBasic, FirstAndLastElement) {
  auto result = FindSumHash(17, 5, {1, 3, 5, 8, 16});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, 17);
}

TEST(FindSumHashBasic, NegativeNumbers) {
  auto result = FindSumHash(1, 5, {-5, -2, 0, 3, 6});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, 1);
}

TEST(FindSumHashBasic, ZeroSum) {
  auto result = FindSumHash(0, 5, {-4, -1, 0, 1, 4});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, 0);
}

TEST(FindSumHashBasic, DuplicateValues) {
  auto result = FindSumHash(10, 4, {5, 5, 8, 9});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, 10);
}

TEST(FindSumHashBasic, TwoElements) {
  auto result = FindSumHash(7, 2, {3, 4});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, 7);
}

TEST(FindSumHashBasic, LargeNumbers) {
  auto result = FindSumHash(2000000, 3, {1, 1000000, 1000000});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, 2000000);
}

TEST(FindSumHashBasic, MiddleElements) {
  auto result = FindSumHash(13, 6, {1, 2, 5, 8, 11, 20});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, 13);
}

TEST(FindSumHashCorner, EmptyArray) {
  auto result = FindSumHash(5, 0, {});

  ASSERT_FALSE(result.find);
}

TEST(FindSumHashCorner, SingleElementNotFound) {
  auto result = FindSumHash(10, 1, {10});

  ASSERT_FALSE(result.find);
}

TEST(FindSumHashCorner, AllNegative) {
  auto result = FindSumHash(-7, 4, {-10, -5, -2, -1});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, -7);
}

TEST(FindSumHashCorner, NoSolutionWithNegatives) {
  auto result = FindSumHash(100, 5, {-5, -2, 0, 3, 6});

  ASSERT_FALSE(result.find);
}

TEST(FindSumHashCorner, PairAtBeginning) {
  auto result = FindSumHash(3, 5, {1, 2, 10, 20, 30});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, 3);
}

TEST(FindSumHashCorner, PairAtEnd) {
  auto result = FindSumHash(50, 5, {1, 2, 10, 20, 30});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, 50);
}

TEST(FindSumHashCorner, MultipleSolutions) {
  auto result = FindSumHash(10, 6, {1, 2, 3, 7, 8, 9});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, 10);
}

TEST(FindSumHashCorner, Zeroes) {
  auto result = FindSumHash(0, 4, {0, 0, 1, 2});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, 0);
}

TEST(FindSumHashCorner, LargeNegativeAndPositive) {
  auto result = FindSumHash(0, 4, {-1000000, -1, 1, 1000000});

  ASSERT_TRUE(result.find);
  ASSERT_EQ(result.a + result.b, 0);
}