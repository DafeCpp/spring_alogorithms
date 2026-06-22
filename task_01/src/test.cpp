#include <gtest/gtest.h>

#include <vector>

#include "findeq.hpp"

TEST(SumOfTwo, Simple) {
  std::vector<int> v = {2, 7, 11, 15};
  ASSERT_EQ(FindEq(9, 4, v), std::make_pair(2, 7));  // Stack []
}

TEST(SumOfTwo, WrongAns) {
  std::vector<int> v = {0, 4, 5, 9};

  ASSERT_EQ(FindEq(1000, 4, v), std::make_pair(-1, -1));
}
TEST(SumOfTwo, EmptyCont) {
  std::vector<int> v = {};
  ASSERT_EQ(FindEq(10, 0, v), std::make_pair(-1, -1));
}

TEST(SumOfTwo, Hard) {
  std::vector<int> v = {0, 10, 15, 20, 25, 30, 40, 50, 75, 95};
  ASSERT_EQ(FindEq(100, 10, v), std::make_pair(25, 75));
}