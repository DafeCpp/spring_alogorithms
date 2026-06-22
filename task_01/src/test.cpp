#include <gtest/gtest.h>

#include <vector>

#include "FindPair.h"
TEST(FindPair, Example1) {
  std::vector<int> v{2, 7, 11, 15};
  ASSERT_EQ((std::vector<int>{2, 7}), FindPair(9, v));
}

TEST(FindPair, Example2) {
  std::vector<int> v{1, 2, 4};
  ASSERT_EQ((std::vector<int>{2, 4}), FindPair(6, v));
}

TEST(FindPair, NoSolution) {
  std::vector<int> v{1, 2, 3};
  ASSERT_EQ((std::vector<int>{-1}), FindPair(100, v));
}

TEST(FindPair, DuplicateElements) {
  std::vector<int> v{2, 2};
  ASSERT_EQ((std::vector<int>{2, 2}), FindPair(4, v));
}

TEST(FindPair, NegativeNumbers) {
  std::vector<int> v{-10, 2, 5};
  ASSERT_EQ((std::vector<int>{-10, 2}), FindPair(-8, v));
}

TEST(FindPair, SingleElement) {
  std::vector<int> v{5};
  ASSERT_EQ((std::vector<int>{-1}), FindPair(10, v));
}