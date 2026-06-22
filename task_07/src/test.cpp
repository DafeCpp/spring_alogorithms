#include <gtest/gtest.h>

#include "heap_sort.hpp"

TEST(HeapSortBasic, AlreadySorted) {
  std::vector<int> input = {1, 2, 3, 4, 5};
  std::vector<int> expected = {1, 2, 3, 4, 5};

  ASSERT_EQ(HeapSort(input), expected);
}

TEST(HeapSortBasic, ReverseSorted) {
  std::vector<int> input = {5, 4, 3, 2, 1};
  std::vector<int> expected = {1, 2, 3, 4, 5};

  ASSERT_EQ(HeapSort(input), expected);
}

TEST(HeapSortBasic, RandomCase1) {
  std::vector<int> input = {3, 1, 4, 1, 5};
  std::vector<int> expected = {1, 1, 3, 4, 5};

  ASSERT_EQ(HeapSort(input), expected);
}

TEST(HeapSortBasic, RandomCase2) {
  std::vector<int> input = {10, -1, 2, 5, 0};
  std::vector<int> expected = {-1, 0, 2, 5, 10};

  ASSERT_EQ(HeapSort(input), expected);
}

TEST(HeapSortBasic, SingleElement) {
  std::vector<int> input = {42};
  std::vector<int> expected = {42};

  ASSERT_EQ(HeapSort(input), expected);
}

TEST(HeapSortBasic, TwoElementsSorted) {
  std::vector<int> input = {1, 2};
  std::vector<int> expected = {1, 2};

  ASSERT_EQ(HeapSort(input), expected);
}

TEST(HeapSortBasic, TwoElementsReversed) {
  std::vector<int> input = {2, 1};
  std::vector<int> expected = {1, 2};

  ASSERT_EQ(HeapSort(input), expected);
}

TEST(HeapSortCorner, Duplicates) {
  std::vector<int> input = {5, 1, 5, 3, 5, 1};
  std::vector<int> expected = {1, 1, 3, 5, 5, 5};

  ASSERT_EQ(HeapSort(input), expected);
}

TEST(HeapSortCorner, NegativeNumbers) {
  std::vector<int> input = {-3, -1, -7, -4, -2};
  std::vector<int> expected = {-7, -4, -3, -2, -1};

  ASSERT_EQ(HeapSort(input), expected);
}

TEST(HeapSortCorner, AlreadyUniform) {
  std::vector<int> input = {7, 7, 7, 7};
  std::vector<int> expected = {7, 7, 7, 7};

  ASSERT_EQ(HeapSort(input), expected);
}

TEST(HeapSortCorner, LargeMix) {
  std::vector<int> input = {100, 0, -100, 50, -50, 25, -25};
  std::vector<int> expected = {-100, -50, -25, 0, 25, 50, 100};

  ASSERT_EQ(HeapSort(input), expected);
}

TEST(HeapSortCorner, EmptyVector) {
  std::vector<int> input = {};
  std::vector<int> expected = {};

  ASSERT_EQ(HeapSort(input), expected);
}