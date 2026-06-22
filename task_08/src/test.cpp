#include <gtest/gtest.h>

#include <vector>

#include "task8.hpp"

TEST(OrderStatisticTest, SimpleTest1) {
  std::vector<int> arr = {7, 10, 4, 3, 20};
  int K = 3;
  int result = findKthOrderStatistic(arr, K);
  EXPECT_EQ(result, 7);
}

TEST(OrderStatisticTest, MinElement) {
  std::vector<int> arr = {7, 10, 4, 3, 20};
  int K = 1;
  int result = findKthOrderStatistic(arr, K);
  EXPECT_EQ(result, 3);
}

TEST(OrderStatisticTest, MaxElement) {
  std::vector<int> arr = {7, 10, 4, 3, 20};
  int K = 5;
  int result = findKthOrderStatistic(arr, K);
  EXPECT_EQ(result, 20);
}

TEST(OrderStatisticTest, NegativeNumbers) {
  std::vector<int> arr = {-5, -10, 0, 3, -1};
  int K = 3;
  int result = findKthOrderStatistic(arr, K);
  EXPECT_EQ(result, -1);  // Отсортированный: -10, -5, -1, 0, 3
}

TEST(OrderStatisticTest, DuplicateNumbers) {
  std::vector<int> arr = {5, 5, 5, 1, 1};
  int K = 3;
  int result = findKthOrderStatistic(arr, K);
  EXPECT_EQ(result, 5);  // Отсортированный: 1, 1, 5, 5, 5
}

TEST(OrderStatisticTest, SingleElement) {
  std::vector<int> arr = {42};
  int K = 1;
  int result = findKthOrderStatistic(arr, K);
  EXPECT_EQ(result, 42);
}

TEST(OrderStatisticTest, TwoElements) {
  std::vector<int> arr = {10, 5};
  int K = 2;
  int result = findKthOrderStatistic(arr, K);
  EXPECT_EQ(result, 10);
}