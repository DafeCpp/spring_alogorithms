#include <gtest/gtest.h>

#include <vector>

#include "../heared/mergeSort.h"

namespace {

std::vector<int> SortCopy(std::vector<int> values) {
  if (!values.empty()) {
    mergeSort<int>(values, 0, values.size() - 1);
  }
  return values;
}

}  // namespace

TEST(MergeSortTest, SortsBasicSequence) {
  EXPECT_EQ(SortCopy({5, 3, 1, 4, 2}), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, KeepsAlreadySortedArray) {
  EXPECT_EQ(SortCopy({1, 2, 3, 4, 5}), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, SortsReverseArray) {
  EXPECT_EQ(SortCopy({5, 4, 3, 2, 1}), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, SortsArrayWithDuplicates) {
  EXPECT_EQ(SortCopy({4, 1, 4, 2, 2, 3}), (std::vector<int>{1, 2, 2, 3, 4, 4}));
}

TEST(MergeSortTest, SortsNegativeNumbers) {
  EXPECT_EQ(SortCopy({-3, 5, 0, -1, 10, -7, 3}),
            (std::vector<int>{-7, -3, -1, 0, 3, 5, 10}));
}

TEST(MergeSortTest, HandlesSingleElement) {
  EXPECT_EQ(SortCopy({42}), (std::vector<int>{42}));
}

TEST(MergeSortTest, HandlesEmptyArray) { EXPECT_TRUE(SortCopy({}).empty()); }
