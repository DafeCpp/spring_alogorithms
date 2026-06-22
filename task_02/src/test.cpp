#include <gtest/gtest.h>

#include "search.hpp"

TEST(Test, FirstElem) {
  std::vector<int> v = {0, 1, 1, 1, 1};
  ASSERT_EQ(Search(v), 0);  // placeholder
}

TEST(Test, Easy) {
  std::vector<int> v = {0, 0, 1, 1, 1};
  ASSERT_EQ(Search(v), 1);  // placeholder
}
TEST(Test, LastElem) {
  std::vector<int> v = {0, 0, 0, 0, 1};
  ASSERT_EQ(Search(v), 3);  // placeholder
}
TEST(Test, Hard) {
  std::vector<int> v = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
  ASSERT_EQ(Search(v), 9);  // placeholder
}
