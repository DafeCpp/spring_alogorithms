#include <gtest/gtest.h>

#include <vector>

#include "task2.hpp"

TEST(Border01, Minimal) {
  std::vector<int> a{0, 1};
  ASSERT_EQ(0, find_index(2, a));
}

TEST(Border01, Middle) {
  std::vector<int> a{0, 0, 0, 1, 1};
  ASSERT_EQ(2, find_index(5, a));
}

TEST(Border01, LastZero) {
  std::vector<int> a{0, 0, 0, 0, 0, 1};
  ASSERT_EQ(4, find_index(6, a));
}

TEST(Border01, FirstBoundary) {
  std::vector<int> a{0, 1, 1, 1, 1};
  ASSERT_EQ(0, find_index(5, a));
}
