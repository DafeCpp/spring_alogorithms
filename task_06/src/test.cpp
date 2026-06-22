#include <gtest/gtest.h>

#include <get_min_cost.hpp>

TEST(Test, Simple) {
  std::vector<double> v1{2, 8, 1, 5};
  ASSERT_DOUBLE_EQ(GetMinCost(3, v1), 6);

  std::vector<double> v2{5, 5, 5, 2, 2, 2};
  ASSERT_DOUBLE_EQ(GetMinCost(3, v2), 21);

  std::vector<double> v3{2, 4, 6, 8, 10, 8, 6, 4, 2};
  ASSERT_DOUBLE_EQ(GetMinCost(3, v3), 36);  // 2+2+2+4+6+6+8+4+2
}

TEST(Test, SingleDay) {
  std::vector<double> v1{5};
  ASSERT_DOUBLE_EQ(GetMinCost(1, v1), 5.0);
}

TEST(Test, TwoDays) {
  std::vector<double> v1{5, 3};
  ASSERT_DOUBLE_EQ(GetMinCost(1, v1), 8.0);  // 5+3
  ASSERT_DOUBLE_EQ(GetMinCost(2, v1), 8.0);  // 5+3
}
TEST(Test, ThreeDays) {
  std::vector<double> v1{5, 3, 4};
  ASSERT_DOUBLE_EQ(GetMinCost(1, v1), 12.0);  // 5+3+4
  ASSERT_DOUBLE_EQ(GetMinCost(2, v1), 11.0);  // 5+3+3
  ASSERT_DOUBLE_EQ(GetMinCost(3, v1), 11.0);  // 5+3+3
}

TEST(Test, IncreasingPrices) {
  std::vector<double> v1{1, 2, 3, 4, 5};
  ASSERT_DOUBLE_EQ(GetMinCost(2, v1), 11.0);  // 1 + 1 + 2 + 3 + 4
}

TEST(Test, DecreasingPrices) {
  std::vector<double> v1{5, 4, 3, 2, 1};
  ASSERT_DOUBLE_EQ(GetMinCost(2, v1), 15.0);
}

TEST(Test, AllSamePrices) {
  std::vector<double> v1{3, 3, 3, 3};
  ASSERT_DOUBLE_EQ(GetMinCost(2, v1), 12.0);  // 3+3+3+3
}

TEST(Test, KBiggerN) {
  std::vector<double> v1{10, 5, 7};
  ASSERT_DOUBLE_EQ(GetMinCost(5, v1), 20);  // 10+5+5
}

TEST(Test, KEqualsN) {
  std::vector<double> v1{8, 3, 6, 2, 9};
  ASSERT_DOUBLE_EQ(GetMinCost(5, v1), 18.0);  // 8+3+3+2+2
}

TEST(Test, KEquals1) {
  std::vector<double> v1{4, 1, 3, 2, 5};
  ASSERT_DOUBLE_EQ(GetMinCost(1, v1), 15.0);  // 4+1+3+2+5
}

TEST(Test, FloatingPrices) {
  std::vector<double> v1{2.5, 1.8, 3.2, 2.1};
  ASSERT_DOUBLE_EQ(GetMinCost(2, v1), 8.2);  // 2.5 + 1.8 + 1.8 + 2.1
  ASSERT_DOUBLE_EQ(GetMinCost(3, v1), 7.9);  // 2.5 + 1.8 + 1.8 + 1.8
}

TEST(Test, LargeK) {
  std::vector<double> v1{100, 1, 100, 1, 100};
  ASSERT_DOUBLE_EQ(GetMinCost(100, v1), 104);  // 100+1+1+1+1
}