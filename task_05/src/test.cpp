#include <gtest/gtest.h>

#include <vector>

#include "merge_sort.h"

TEST(MergeSortTest, EmptyArray) {
  std::vector<int> arr = {};
  std::vector<int> expected = {};
  mergeSort(arr, 0, arr.size());
  EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, SingleElement) {
  std::vector<int> arr = {5};
  std::vector<int> expected = {5};
  mergeSort(arr, 0, arr.size());
  EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, AlreadySorted) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  std::vector<int> expected = {1, 2, 3, 4, 5};
  mergeSort(arr, 0, arr.size());
  EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, ReverseSorted) {
  std::vector<int> arr = {5, 4, 3, 2, 1};
  std::vector<int> expected = {1, 2, 3, 4, 5};
  mergeSort(arr, 0, arr.size());
  EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, RandomOrder) {
  std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
  std::vector<int> expected = {1, 1, 2, 3, 4, 5, 6, 9};
  mergeSort(arr, 0, arr.size());
  EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, PartialSort) {
  std::vector<int> arr = {7, 6, 5, 1, 2, 3, 4};
  std::vector<int> expected_full = {1, 2, 3, 4, 5, 6, 7};
  std::vector<int> expected_partial = {5, 6, 7, 1,
                                       2, 3, 4};  // если сортировать часть

  // Тестируем полную сортировку
  mergeSort(arr, 0, arr.size());
  EXPECT_EQ(arr, expected_full);

  // Тестируем частичную сортировку (первые 3 элемента)
  arr = {7, 6, 5, 1, 2, 3, 4};
  mergeSort(arr, 0, 3);
  expected_partial = {5, 6, 7, 1, 2, 3, 4};
  EXPECT_EQ(arr, expected_partial);
}

TEST(MergeSortTest, MergeFunction) {
  std::vector<int> arr = {1, 3, 5, 2, 4, 6};
  std::vector<int> merged = merge(arr, 0, 3, 6);
  std::vector<int> expected = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(merged, expected);
}