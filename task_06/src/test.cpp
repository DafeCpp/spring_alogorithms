#include <gtest/gtest.h>

#include "solution.hpp"
TEST(Fish, Basic1) {
  std::vector<int> prices = {5};
  ASSERT_EQ(5, CalcCost(1, 1, prices));
}
TEST(Fish, Basic2) {
  std::vector<int> prices = {5, 3, 4};
  ASSERT_EQ(12, CalcCost(3, 1, prices));
}
TEST(Fish, Basic3) {
  std::vector<int> prices = {5, 3, 4};
  ASSERT_EQ(11, CalcCost(3, 3, prices));
}

TEST(Fish, Decreasings) {
  std::vector<int> prices = {10, 9, 8, 7};
  int k = 2;
  ASSERT_EQ(34, CalcCost(4, 2, prices));
}