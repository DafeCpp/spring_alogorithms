#include <gtest/gtest.h>

#include <cmath>
#include <util.hpp>

TEST(Test1_Simple_Test, Simple) {
  std::vector<int> v = {1, 2, 3, 4, 5, 6};

  auto result = func(7, v);
  EXPECT_EQ(result.first, 1);
  EXPECT_EQ(result.second, 6);
}

TEST(Test2, Empty) {
  std::vector<int> v = {};

  auto result = func(7, v);
  EXPECT_EQ(result.first, 0);
  EXPECT_EQ(result.second, 0);
}

TEST(Test3, Small) {
  std::vector<int> v = {5};

  auto result = func(7, v);
  EXPECT_EQ(result.first, 0);
  EXPECT_EQ(result.second, 0);
}

TEST(Test4, No_Pair) {
  std::vector<int> v = {1, 3, 5, 7};

  auto result = func(40, v);
  EXPECT_EQ(result.first, -1);
  EXPECT_EQ(result.second, -1);
}

TEST(Test5, With_Negative) {
  std::vector<int> v = {-4, -1, 3, 8};
  auto result = func(-5, v);
  EXPECT_EQ(result.first, -1);
  EXPECT_EQ(result.second, -4);
}
