#include <gtest/gtest.h>

#include "task.hpp"

TEST(Task1, Simple) {
  std::vector<int> data{1, 3, 4, 4, 7, 11};
  std::pair<int, int> ans{3, 7};
  ASSERT_EQ(SearchNumbers(10, data), ans);
}

TEST(Task1, FirstAndLast) {
  std::vector<int> data{1, 2, 3, 4, 5, 99};
  std::pair<int, int> ans{1, 99};
  ASSERT_EQ(SearchNumbers(100, data), ans);
}

TEST(Task1, Negative) {
  std::vector<int> data{-5, -3, 0, 1, 2, 8};
  std::pair<int, int> ans{-3, 8};
  ASSERT_EQ(SearchNumbers(5, data), ans);
}

TEST(Task1, Simple2) {
  std::vector<int> data{10, 11, 12, 13, 14, 15};
  std::pair<int, int> ans{10, 15};
  ASSERT_EQ(SearchNumbers(25, data), ans);
}

TEST(Task1, SmallVector) {
  std::vector<int> data{1, 2};
  std::pair<int, int> ans{1, 2};
  ASSERT_EQ(SearchNumbers(3, data), ans);
}

TEST(Task1, NoPair) {
  std::vector<int> data{1, 2, 3, 4, 5};
  ASSERT_THROW(SearchNumbers(100, data), std::invalid_argument);
}

TEST(Task1, Empty) {
  std::vector<int> data;
  ASSERT_THROW(SearchNumbers(10, data), std::invalid_argument);
}

TEST(Task1, SingleElementVector) {
  std::vector<int> data{5};
  ASSERT_THROW(SearchNumbers(5, data), std::invalid_argument);
}
