#include <gtest/gtest.h>

#include <vector>

#include "task7.hpp"

TEST(QuickSort, Example1) {
  std::vector<int> v{5, 3, 1, 4, 2};
  if (!v.empty()) {
    quickSort(v, 0, v.size() - 1);
  }
  std::vector<int> expect{1, 2, 3, 4, 5};
  ASSERT_EQ(expect, v);
}

TEST(QuickSort, ExampleDuplicates) {
  std::vector<int> v{3, 3, 1, 1, 2, 2};
  if (!v.empty()) {
    quickSort(v, 0, v.size() - 1);
  }
  std::vector<int> expect{1, 1, 2, 2, 3, 3};
  ASSERT_EQ(expect, v);
}

TEST(QuickSort, ExampleNegatives) {
  std::vector<int> v{-3, 5, 0, -1, 10, -7, 3};
  if (!v.empty()) {
    quickSort(v, 0, v.size() - 1);
  }
  std::vector<int> expect{-7, -3, -1, 0, 3, 5, 10};
  ASSERT_EQ(expect, v);
}

TEST(QuickSort, Empty) {
  std::vector<int> v{};
  if (!v.empty()) {
    quickSort(v, 0, v.size() - 1);
  }
  std::vector<int> expect{};
  ASSERT_EQ(expect, v);
}
