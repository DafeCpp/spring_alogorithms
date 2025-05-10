
#include <gtest/gtest.h>

#include "search_statistic.hpp"

TEST(SearchNStatistics, Simple) {
  std::vector<double> v = {5, 3, 1, 4, 2};
  ASSERT_EQ(SearchNStatistics(v, 0), 1);
  ASSERT_EQ(SearchNStatistics(v, 2), 3);
  ASSERT_EQ(SearchNStatistics(v, 4), 5);
}

TEST(SearchNStatistics, Same) {
  std::vector<double> v = {1, 1, 1, 1, 1, 3};
  ASSERT_EQ(SearchNStatistics(v, 2), 1);
  ASSERT_EQ(SearchNStatistics(v, 0), 1);
  ASSERT_EQ(SearchNStatistics(v, 5), 3);
}

TEST(SearchNStatistics, Empty) {
  std::vector<double> v;
  EXPECT_THROW(SearchNStatistics(v, 0), std::invalid_argument);
}

TEST(SearchNStatistics, OrderException) {
  std::vector<double> v = {42.0};
  EXPECT_THROW(SearchNStatistics(v, 1), std::invalid_argument);
}

TEST(SearchNStatistics, InvalidOrder) {
  std::vector<double> v = {42.0};
  EXPECT_THROW(SearchNStatistics(v, -3), std::invalid_argument);
}

TEST(SearchNStatistics, Sorted) {
  std::vector<double> v = {0, 1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ(SearchNStatistics(v, 0), 0);
  EXPECT_EQ(SearchNStatistics(v, 3), 3);
  EXPECT_EQ(SearchNStatistics(v, 6), 6);
}

TEST(SearchNStatistics, NegativeNumbers) {
  std::vector<double> v = {-5, -1, -3, -2, -4};
  EXPECT_EQ(SearchNStatistics(v, 0), -5);
  EXPECT_EQ(SearchNStatistics(v, 2), -3);
  EXPECT_EQ(SearchNStatistics(v, 4), -1);
}