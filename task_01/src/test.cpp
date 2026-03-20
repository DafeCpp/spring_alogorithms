#include <gtest/gtest.h>

#include <util.hpp>

TEST(Test1, Simple) {
  std::vector<int> v = {1, 2, 3, 4, 5, 6};

  auto result = fun(7, v);
  EXPECT_EQ(result.first, 1);
  EXPECT_EQ(result.second, 6);
}

TEST(Test2, Empty) {
  std::vector<int> v = {};

  auto result = fun(7, v);
  EXPECT_EQ(result.first, 0);
  EXPECT_EQ(result.second, 0);
}

TEST(Test3, Small) {
  std::vector<int> v = {2};

  auto result = fun(7, v);
  EXPECT_EQ(result.first, 0);
  EXPECT_EQ(result.second, 0);
}

TEST(Test4, No_pair) {
  std::vector<int> v = {2, 5, 7, 8, 9, 14};

  auto result = fun(52, v);
  EXPECT_EQ(result.first, -1);
  EXPECT_EQ(result.second, -1);
}

TEST(Test5, Negative_number) {
  std::vector<int> v = {-1, 3, -4, 8};

  auto result = fun(-5, v);
  EXPECT_EQ(result.first, -1);
  EXPECT_EQ(result.second, -4);
}
