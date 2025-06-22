#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "QuickSort.hpp"

namespace {
  bool isSorted(const std::vector<int>& arr) {
    return std::is_sorted(arr.begin(), arr.end());
  }
}

TEST(QuickSortTest, AlreadySorted) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  quickSort(arr);
  EXPECT_TRUE(isSorted(arr));
}

TEST(QuickSortTest, ReverseSorted) {
  std::vector<int> arr = {5, 4, 3, 2, 1};
  quickSort(arr);
  EXPECT_TRUE(isSorted(arr));
}

TEST(QuickSortTest, RandomOrder) {
  std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2};
  quickSort(arr);
  EXPECT_TRUE(isSorted(arr));
}

TEST(QuickSortTest, EmptyArray) {
  std::vector<int> arr;
  quickSort(arr);
  EXPECT_TRUE(arr.empty());
}

TEST(QuickSortTest, SingleElement) {
  std::vector<int> arr = {42};
  quickSort(arr);
  EXPECT_EQ(arr, std::vector<int>({42}));
}

TEST(QuickSortTest, TwoElementsSorted) {
  std::vector<int> arr = {1, 2};
  quickSort(arr);
  EXPECT_EQ(arr, std::vector<int>({1, 2}));
}

TEST(QuickSortTest, TwoElementsUnsorted) {
  std::vector<int> arr = {2, 1};
  quickSort(arr);
  EXPECT_EQ(arr, std::vector<int>({1, 2}));
}

TEST(QuickSortTest, AllEqualElements) {
  std::vector<int> arr = {7, 7, 7, 7, 7};
  quickSort(arr);
  EXPECT_EQ(arr, std::vector<int>({7, 7, 7, 7, 7}));
}

TEST(QuickSortTest, ContainsNegatives) {
  std::vector<int> arr = {-3, -1, -4, -2, 0};
  quickSort(arr);
  EXPECT_TRUE(isSorted(arr));
}

TEST(QuickSortTest, DuplicatesAndUnique) {
  std::vector<int> arr = {4, 1, 3, 4, 2, 4, 5};
  quickSort(arr);
  EXPECT_TRUE(isSorted(arr));
}

TEST(QuickSortTest, LargeInput) {
  std::vector<int> arr(1000);
  for (int i = 0; i < 1000; ++i) arr[i] = rand() % 10000;
  quickSort(arr);
  EXPECT_TRUE(isSorted(arr));
}
