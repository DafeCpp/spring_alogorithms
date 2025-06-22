#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "ord_stat.hpp"

TEST(OrdStatTest, MinimumElement) {
  std::vector<int> arr = {4, 2, 5, 1, 3};
  EXPECT_EQ(ordstat(arr, 0), 1);
}

TEST(OrdStatTest, MaximumElement) {
  std::vector<int> arr = {7, 8, 2, 5, 9};
  EXPECT_EQ(ordstat(arr, arr.size() - 1), 9);
}

TEST(OrdStatTest, MedianElementOdd) {
  std::vector<int> arr = {5, 1, 9, 3, 7};
  EXPECT_EQ(ordstat(arr, 2), 5);
}

TEST(OrdStatTest, MedianElementEven) {
  std::vector<int> arr = {10, 20, 30, 40};
  int result = ordstat(arr, 1);
  EXPECT_EQ(result, 20);
}

TEST(OrdStatTest, AllEqualElements) {
  std::vector<int> arr = {6, 6, 6, 6, 6};
  EXPECT_EQ(ordstat(arr, 3), 6);
}

TEST(OrdStatTest, ContainsNegatives) {
  std::vector<int> arr = {-5, -10, 0, 5, 10};
  EXPECT_EQ(ordstat(arr, 1), -5);
  EXPECT_EQ(ordstat(arr, 4), 10);
}

TEST(OrdStatTest, DuplicatesInArray) {
  std::vector<int> arr = {4, 1, 4, 2, 2, 3};
  EXPECT_EQ(ordstat(arr, 3), 3);
}

TEST(OrdStatTest, SingleElement) {
  std::vector<int> arr = {99};
  EXPECT_EQ(ordstat(arr, 0), 99);
}

TEST(OrdStatTest, LargeArrayRandom) {
  std::vector<int> arr(1000);
  for (int i = 0; i < 1000; ++i) arr[i] = rand() % 10000;
  std::vector<int> sorted = arr;
  std::sort(sorted.begin(), sorted.end());
  EXPECT_EQ(ordstat(arr, 500), sorted[500]);
}