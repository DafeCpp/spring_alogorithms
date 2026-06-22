#include <gtest/gtest.h>

#include <vector>

#include "statistic.hpp"

TEST(ReturnKthTest, FindMinimum) {
  std::vector<int> vec = {5, 2, 9, 1, 7, 3};
  int result = ReturnKth(1, vec, 0, vec.size() - 1);
  EXPECT_EQ(result, 1);
}

TEST(ReturnKthTest, FindMaximum) {
  std::vector<int> vec = {5, 2, 9, 1, 7, 3};
  int result = ReturnKth(6, vec, 0, vec.size() - 1);
  EXPECT_EQ(result, 9);
}

TEST(ReturnKthTest, FindMiddle) {
  std::vector<int> vec = {5, 2, 9, 1, 7, 3};
  int result = ReturnKth(3, vec, 0, vec.size() - 1);
  EXPECT_EQ(result, 3);
}

TEST(ReturnKthTest, WithDuplicates) {
  std::vector<int> vec = {3, 5, 3, 3, 8, 3, 1};
  int result = ReturnKth(4, vec, 0, vec.size() - 1);
  EXPECT_EQ(result, 3);
}

TEST(ReturnKthTest, AlreadySorted) {
  std::vector<int> vec = {10, 20, 30, 40, 50};
  int result = ReturnKth(2, vec, 0, vec.size() - 1);
  EXPECT_EQ(result, 20);
}
