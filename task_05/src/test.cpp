#include <gtest/gtest.h>

#include "sorting.hpp"

TEST(MergeSort, Simple) {
  std ::vector<int> unsort{3, 2, 4, 5, 1, 9, 7};
  std ::vector<int> sorted{1, 2, 3, 4, 5, 7, 9};
  MergeSort(unsort);
  ASSERT_EQ(unsort, sorted);
}

TEST(MergeSort, Simple2) {
  std ::vector<int> unsort{5, 7, 2, 3, 1, 6, 4};
  std ::vector<int> sorted{1, 2, 3, 4, 5, 6, 7};
  MergeSort(unsort);
  ASSERT_EQ(unsort, sorted);
}

TEST(MergeSort, Negative) {
  std ::vector<int> unsort{-5, -7, -2, -3, -1, -6, -4};
  std ::vector<int> sorted{-7, -6, -5, -4, -3, -2, -1};
  MergeSort(unsort);
  ASSERT_EQ(unsort, sorted);
}

TEST(MergeSort, SameElements) {
  std ::vector<int> unsort{3, 3, 3, 3};
  std ::vector<int> sorted{3, 3, 3, 3};
  MergeSort(unsort);
  ASSERT_EQ(unsort, sorted);
}

TEST(MergeSort, NoElements) {
  std ::vector<int> unsort{};
  std ::vector<int> sorted{};
  MergeSort(unsort);
  ASSERT_EQ(unsort, sorted);
}

TEST(MergeSort, DiffElements) {
  std ::vector<int> unsort{1, -3, 5, 0, 0, -10, 6, 2, 21, -8, 90, -6};
  std ::vector<int> sorted{-10, -8, -6, -3, 0, 0, 1, 2, 5, 6, 21, 90};
  MergeSort(unsort);
  ASSERT_EQ(unsort, sorted);
}

TEST(MergeSort, OneElement) {
  std ::vector<int> unsort{10};
  std ::vector<int> sorted{10};
  MergeSort(unsort);
  ASSERT_EQ(unsort, sorted);
}