#include <gtest/gtest.h>

#include <algorithm>
#include <stdexcept>
#include <vector>

#include "task_01.hpp"

TEST(FindTwoNumsTest, BasicMatch) {
  std::vector<int> arr = {1, 2, 3, 4, 6};
  auto result = FindTwoNums(7, arr);
  std::sort(result.begin(), result.end());
  ASSERT_EQ(result, std::vector<int>({1, 6}));
}

TEST(FindTwoNumsTest, MultiplePairsPossible) {
  std::vector<int> arr = {1, 2, 3, 4, 4, 5};
  auto result = FindTwoNums(8, arr);
  ASSERT_EQ(result[0] + result[1], 8);
}

TEST(FindTwoNumsTest, NoSolution) {
  std::vector<int> arr = {1, 2, 3};
  ASSERT_EQ(FindTwoNums(10, arr), std::vector<int>{});
}

TEST(FindTwoNumsTest, NegativeNumbers) {
  std::vector<int> arr = {-5, -2, 0, 3, 7, 9};
  auto result = FindTwoNums(4, arr);
  std::sort(result.begin(), result.end());
  ASSERT_EQ(result, std::vector<int>({-5, 9}));
}

TEST(FindTwoNumsTest, SameElementTwice) {
  std::vector<int> arr = {1, 2, 4, 4, 5, 6};
  auto result = FindTwoNums(8, arr);
  std::sort(result.begin(), result.end());
  ASSERT_EQ(result, std::vector<int>({2, 6}));
}