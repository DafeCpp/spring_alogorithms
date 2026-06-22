#include <gtest/gtest.h>

#include <vector>

#include "task1.hpp"
TEST(FindPair, Example1) {
  std::vector<int> v{2, 7, 11, 15};
  ASSERT_EQ((std::vector<int>{2, 7}), sum_of_two(9, 4, v));
}

TEST(FindPair, Example2) {
  std::vector<int> v{1, 2, 4};
  ASSERT_EQ((std::vector<int>{2, 4}), sum_of_two(6, 3, v));
}

TEST(FindPair, NoSolution) {
  std::vector<int> v{1, 2, 3};
  ASSERT_EQ((std::vector<int>{-1}), sum_of_two(100, 3, v));
}

TEST(FindPair, DuplicateElements) {
  std::vector<int> v{2, 2};
  ASSERT_EQ((std::vector<int>{2, 2}), sum_of_two(4, 2, v));
}

TEST(FindPair, NegativeNumbers) {
  std::vector<int> v{-10, 2, 5};
  ASSERT_EQ((std::vector<int>{-10, 2}), sum_of_two(-8, 3, v));
}

TEST(FindPair, SingleElement) {
  std::vector<int> v{5};
  ASSERT_EQ((std::vector<int>{-1}), sum_of_two(10, 1, v));
}