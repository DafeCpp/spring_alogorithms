#include <gtest/gtest.h>

#include "./task_01.h"

TEST(FindValues, Simple) {
  std::vector<int> v = {1, 2, 4};
  ASSERT_EQ(FindValues(6, 3, v), std::make_pair(2, 4));
}

// Test basic functionality with simple cases
TEST(FindValuesTest, SimpleCases) {
  std::vector<int> v1 = {2, 7, 11, 15};
  EXPECT_EQ(FindValues(9, 4, v1), std::make_pair(2, 7));

  std::vector<int> v2 = {1, 2, 3};
  EXPECT_EQ(FindValues(6, 3, v2), std::make_pair(-1, -1));
}

// Test with empty array
TEST(FindValuesTest, EmptyArray) {
  std::vector<int> v;
  EXPECT_EQ(FindValues(5, 0, v), std::make_pair(-1, -1));
}

// Test with single element array
TEST(FindValuesTest, SingleElement) {
  std::vector<int> v = {5};
  EXPECT_EQ(FindValues(5, 1, v), std::make_pair(-1, -1));
  EXPECT_EQ(FindValues(10, 1, v), std::make_pair(-1, -1));
}

// Test with array of size 2
TEST(FindValuesTest, TwoElements) {
  std::vector<int> v = {2, 3};
  EXPECT_EQ(FindValues(5, 2, v), std::make_pair(2, 3));
  EXPECT_EQ(FindValues(6, 2, v), std::make_pair(-1, -1));
}

// Test with negative numbers
TEST(FindValuesTest, NegativeNumbers) {
  std::vector<int> v = {-5, -2, 0, 1, 3, 7};
  EXPECT_EQ(FindValues(-7, 6, v), std::make_pair(-5, -2));
  EXPECT_EQ(FindValues(5, 6, v), std::make_pair(-2, 7));
  EXPECT_EQ(FindValues(0, 6, v), std::make_pair(-1, -1));
  EXPECT_EQ(FindValues(-1, 6, v), std::make_pair(-2, 1));
  EXPECT_EQ(FindValues(4, 6, v), std::make_pair(1, 3));
}

// Test with zeros
TEST(FindValuesTest, WithZeros) {
  std::vector<int> v = {0, 0, 2, 5};
  EXPECT_EQ(FindValues(0, 4, v), std::make_pair(0, 0));
  EXPECT_EQ(FindValues(2, 4, v), std::make_pair(0, 2));
}

// Test with duplicate numbers
TEST(FindValuesTest, DuplicateNumbers) {
  std::vector<int> v = {1, 1, 2, 3, 4, 4, 5};
  EXPECT_EQ(FindValues(2, 7, v), std::make_pair(1, 1));
  EXPECT_EQ(FindValues(8, 7, v), std::make_pair(3, 5));
  EXPECT_EQ(FindValues(9, 7, v), std::make_pair(4, 5));
}

// Test with boundary values
TEST(FindValuesTest, BoundaryValues) {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // Sum using first and last elements
  EXPECT_EQ(FindValues(11, 10, v), std::make_pair(1, 10));
  // Sum using middle elements
  EXPECT_EQ(FindValues(13, 10, v), std::make_pair(3, 10));
}

// Test where multiple pairs exist - should return first found pair (smallest
// left element)
TEST(FindValuesTest, MultiplePairs) {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  // Pairs that sum to 8: (1,7), (2,6), (3,5)
  EXPECT_EQ(FindValues(8, 7, v), std::make_pair(1, 7));
}

// Test with large numbers
TEST(FindValuesTest, LargeNumbers) {
  std::vector<int> v = {100, 200, 300, 400, 500, 600};
  EXPECT_EQ(FindValues(900, 6, v), std::make_pair(300, 600));
  EXPECT_EQ(FindValues(1100, 6, v), std::make_pair(500, 600));
}

// Test where left and right pointers cross without finding solution
TEST(FindValuesTest, NoSolution) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(FindValues(10, 5, v), std::make_pair(-1, -1));
  EXPECT_EQ(FindValues(1, 5, v), std::make_pair(-1, -1));
}
