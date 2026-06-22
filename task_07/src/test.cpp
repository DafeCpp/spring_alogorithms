#include <gtest/gtest.h>

#include "merge_sort.hpp"

TEST(MergeSort, HandlesEmptyVector) {
  std::vector<int> values;
  MergeSort(values);
  EXPECT_TRUE(values.empty());
}

TEST(MergeSort, HandlesSingleElement) {
  std::vector<int> values = {42};
  MergeSort(values);
  EXPECT_EQ(values, (std::vector<int>{42}));
}

TEST(MergeSort, KeepsSortedVectorSorted) {
  std::vector<int> values = {1, 2, 3, 4, 5};
  MergeSort(values);
  EXPECT_EQ(values, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSort, SortsValues) {
  std::vector<int> values = {5, 3, 1, 4, 2};
  MergeSort(values);
  EXPECT_EQ(values, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSort, HandlesDuplicates) {
  std::vector<int> values = {3, 3, 1, 1, 2, 2};
  MergeSort(values);
  EXPECT_EQ(values, (std::vector<int>{1, 1, 2, 2, 3, 3}));
}

TEST(MergeSort, HandlesNegativeValues) {
  std::vector<int> values = {-3, 5, 0, -1, 10, -7, 3};
  MergeSort(values);
  EXPECT_EQ(values, (std::vector<int>{-7, -3, -1, 0, 3, 5, 10}));
}
