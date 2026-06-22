#include <gtest/gtest.h>

#include "task7.hpp"

TEST(HeapSortTest, FiveElements) {
  std::vector<int> arr = {5, 3, 1, 4, 2};
  std::vector<int> expected = {1, 2, 3, 4, 5};
  heapSort(arr);
  EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, Duplicates) {
  std::vector<int> arr = {3, 3, 1, 1, 2, 2};
  std::vector<int> expected = {1, 1, 2, 2, 3, 3};
  heapSort(arr);
  EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, NegativeNumbers) {
  std::vector<int> arr = {-3, 5, 0, -1, 10, -7, 3};
  std::vector<int> expected = {-7, -3, -1, 0, 3, 5, 10};
  heapSort(arr);
  EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, OneElement) {
  std::vector<int> arr = {42};
  std::vector<int> expected = {42};
  heapSort(arr);
  EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, TwoElements) {
  std::vector<int> arr = {2, 1};
  std::vector<int> expected = {1, 2};
  heapSort(arr);
  EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, AlreadySorted) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  std::vector<int> expected = {1, 2, 3, 4, 5};
  heapSort(arr);
  EXPECT_EQ(arr, expected);
}

TEST(HeapSortTest, ReverseSorted) {
  std::vector<int> arr = {5, 4, 3, 2, 1};
  std::vector<int> expected = {1, 2, 3, 4, 5};
  heapSort(arr);
  EXPECT_EQ(arr, expected);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}