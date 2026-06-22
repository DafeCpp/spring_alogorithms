
#include <gtest/gtest.h>

#include <vector>

#include "QuickSelect.h"

TEST(QuickSelect, ExamplesFromReadme) {
  std::vector<int> a1 = {7, 10, 4, 3, 20};
  ASSERT_EQ(7, QuickSelect(3, a1));

  std::vector<int> a2 = {7, 10, 4, 3, 20};
  ASSERT_EQ(3, QuickSelect(1, a2));

  std::vector<int> a3 = {7, 10, 4, 3, 20};
  ASSERT_EQ(20, QuickSelect(5, a3));
}

TEST(QuickSelect, DuplicatesAndNegatives) {
  std::vector<int> v = {5, -1, 5, 2, 2, -1};
  // Sorted: -1, -1, 2, 2, 5, 5
  ASSERT_EQ(-1, QuickSelect(1, v));
  ASSERT_EQ(-1, QuickSelect(2, v));
  ASSERT_EQ(2, QuickSelect(3, v));
  ASSERT_EQ(5, QuickSelect(6, v));
}

TEST(QuickSelect, SingleElement) {
  std::vector<int> v = {42};
  ASSERT_EQ(42, QuickSelect(1, v));
}

TEST(QuickSelect, AlreadySorted) {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_EQ(4, QuickSelect(4, v));
  ASSERT_EQ(9, QuickSelect(9, v));
}
