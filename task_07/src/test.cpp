#include <gtest/gtest.h>
#include "mergesort.hpp"
#include <vector>

TEST(MergeSort, Example1) {
  std::vector<int> v{5,3,1,4,2};
  merge_sort(v);
  std::vector<int> expect{1,2,3,4,5};
  ASSERT_EQ(expect, v);
}

TEST(MergeSort, ExampleDuplicates) {
  std::vector<int> v{3,3,1,1,2,2};
  merge_sort(v);
  std::vector<int> expect{1,1,2,2,3,3};
  ASSERT_EQ(expect, v);
}

TEST(MergeSort, ExampleNegatives) {
  std::vector<int> v{-3,5,0,-1,10,-7,3};
  merge_sort(v);
  std::vector<int> expect{-7,-3,-1,0,3,5,10};
  ASSERT_EQ(expect, v);
}

TEST(MergeSort, Empty) {
  std::vector<int> v{};
  merge_sort(v);
  std::vector<int> expect{};
  ASSERT_EQ(expect, v);
}

TEST(MergeSort, SingleElement) {
  std::vector<int> v{42};
  merge_sort(v);
  std::vector<int> expect{42};
  ASSERT_EQ(expect, v);
}

TEST(MergeSort, AlreadySorted) {
  std::vector<int> v{1,2,3,4,5,6};
  merge_sort(v);
  std::vector<int> expect{1,2,3,4,5,6};
  ASSERT_EQ(expect, v);
}

TEST(MergeSort, ReverseSorted) {
  std::vector<int> v{6,5,4,3,2,1};
  merge_sort(v);
  std::vector<int> expect{1,2,3,4,5,6};
  ASSERT_EQ(expect, v);
}
