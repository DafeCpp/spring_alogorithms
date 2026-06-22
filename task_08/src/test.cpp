#include <gtest/gtest.h>

#include <vector>

#include "task8.hpp"

TEST(KthElement, FindMinimum) {
  std::vector<int> v{5, 3, 1, 4, 2};
  int result = (v, 0, v.size() - 1, 1);
  ASSERT_EQ(1, result);
}

TEST(KthElement, FindMaximum) {
  std::vector<int> v{5, 3, 1, 4, 2};
  int result = Select(v, 0, v.size() - 1, 5);
  ASSERT_EQ(5, result);
}

TEST(KthElement, FindMedian) {
  std::vector<int> v{7, 10, 4, 3, 20, 15};
  int result = Select(v, 0, v.size() - 1, 3);
  ASSERT_EQ(7, result);
}

TEST(KthElement, WithDuplicates) {
  std::vector<int> v{3, 1, 2, 1, 3, 2};
  int result = Select(v, 0, v.size() - 1, 4);
  ASSERT_EQ(2, result);
}

TEST(KthElement, WithNegatives) {
  std::vector<int> v{-5, 0, -10, 10, 5};
  int result = Select(v, 0, v.size() - 1, 2);
  ASSERT_EQ(-5, result);
}
