
#include <gtest/gtest.h>

#include <vector>

#include "quick_sort.hpp"

TEST(QuickSort, Simple) {
  std::vector<double> vec{5.0, 6.3, 5.0, 1, -7.3, 3.3, 2.1, 2.1};
  std::vector<double> ans{-7.3, 1, 2.1, 2.1, 3.3, 5, 5, 6.3};
  ASSERT_EQ(QuickSort(vec), ans);
}

TEST(QuickSort, Simple2) {
  std::vector<double> vec{0.001, 0.008, 0.004, 0.006, 0.007, 0.007};
  std::vector<double> ans{0.001, 0.004, 0.006, 0.007, 0.007, 0.008};
  ASSERT_EQ(QuickSort(vec), ans);
}

TEST(QuickSort, Same) {
  std::vector<double> vec{4.2, 4.2, 4.2, 4.2, 4.2};
  std::vector<double> ans{4.2, 4.2, 4.2, 4.2, 4.2};
  ASSERT_EQ(QuickSort(vec), ans);
}

TEST(QuickSort, Already) {
  std::vector<double> vec{-2.2, -1.1, 0, 3.3};
  std::vector<double> ans{-2.2, -1.1, 0, 3.3};
  ASSERT_EQ(QuickSort(vec), ans);
}

TEST(QuickSort, Decrease) {
  std::vector<double> vec{9.9, 7.7, 5.5, 1.1, -0.7};
  std::vector<double> ans{-0.7, 1.1, 5.5, 7.7, 9.9};
  ASSERT_EQ(QuickSort(vec), ans);
}

TEST(QuickSort, Empty) {
  std::vector<double> vec{};
  std::vector<double> ans{};
  ASSERT_EQ(QuickSort(vec), ans);
}
