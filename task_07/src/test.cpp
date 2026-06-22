#include <gtest/gtest.h>

#include <vector>

#include "merge_sort.hpp"

TEST(MergeSort, Simple) {
  std::vector<int> arr = {4, 3, 2, 1};
  std::vector<int> expected = {1, 2, 3, 4};
  std::vector<int> res = MergeSort(arr);
  ASSERT_EQ(res, expected);
}
TEST(MergeSort, Empty) {
  std::vector<int> arr = {};
  std::vector<int> expected = {};
  ASSERT_EQ(MergeSort(arr), expected);
}

TEST(MergeSort, OneElement) {
  std::vector<int> arr = {42};
  std::vector<int> expected = {42};
  ASSERT_EQ(MergeSort(arr), expected);
}

TEST(MergeSort, Duplicates) {
  std::vector<int> arr = {3, 1, 3, 2, 1};
  std::vector<int> expected = {1, 1, 2, 3, 3};
  ASSERT_EQ(MergeSort(arr), expected);
}

TEST(MergeSort, Sorted) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  std::vector<int> expected = {1, 2, 3, 4, 5};
  ASSERT_EQ(MergeSort(arr), expected);
}