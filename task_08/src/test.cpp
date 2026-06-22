#include <gtest/gtest.h>

#include "order_statistic.hpp"

TEST(OrderStatisticBasic, Example1) {
  ASSERT_EQ(OrderStatistic(5, 3, {7, 10, 4, 3, 20}), 7);
}

TEST(OrderStatisticBasic, Example2) {
  ASSERT_EQ(OrderStatistic(5, 1, {7, 10, 4, 3, 20}), 3);
}

TEST(OrderStatisticBasic, Example3) {
  ASSERT_EQ(OrderStatistic(5, 5, {7, 10, 4, 3, 20}), 20);
}

TEST(OrderStatisticBasic, TwoElementsMinimum) {
  ASSERT_EQ(OrderStatistic(2, 1, {10, 5}), 5);
}

TEST(OrderStatisticBasic, TwoElementsMaximum) {
  ASSERT_EQ(OrderStatistic(2, 2, {10, 5}), 10);
}

TEST(OrderStatisticBasic, AlreadySorted) {
  ASSERT_EQ(OrderStatistic(5, 4, {1, 2, 3, 4, 5}), 4);
}

TEST(OrderStatisticBasic, ReverseSorted) {
  ASSERT_EQ(OrderStatistic(5, 2, {5, 4, 3, 2, 1}), 2);
}

TEST(OrderStatisticBasic, NegativeNumbers) {
  ASSERT_EQ(OrderStatistic(5, 3, {-10, -5, -20, 0, 10}), -5);
}

TEST(OrderStatisticBasic, MixedNumbers) {
  ASSERT_EQ(OrderStatistic(7, 5, {-10, 100, 0, 7, -3, 5, 20}), 7);
}

TEST(OrderStatisticBasic, SingleElement) {
  ASSERT_EQ(OrderStatistic(1, 1, {42}), 42);
}

TEST(OrderStatisticCorner, AllEqual) {
  ASSERT_EQ(OrderStatistic(5, 3, {7, 7, 7, 7, 7}), 7);
}

TEST(OrderStatisticCorner, DuplicateValues) {
  ASSERT_EQ(OrderStatistic(6, 4, {1, 5, 5, 2, 5, 3}), 5);
}

TEST(OrderStatisticCorner, MinimumWithDuplicates) {
  ASSERT_EQ(OrderStatistic(6, 1, {5, 1, 1, 3, 2, 1}), 1);
}

TEST(OrderStatisticCorner, MaximumWithDuplicates) {
  ASSERT_EQ(OrderStatistic(6, 6, {5, 1, 1, 3, 2, 1}), 5);
}

TEST(OrderStatisticCorner, KInMiddleWithDuplicates) {
  ASSERT_EQ(OrderStatistic(7, 4, {4, 1, 4, 2, 4, 3, 4}), 4);
}

TEST(OrderStatisticCorner, LargePositiveValues) {
  ASSERT_EQ(OrderStatistic(5, 4, {1000000000, 999999999, 123456789, 42, 7}),
            999999999);
}

TEST(OrderStatisticCorner, LargeNegativeValues) {
  ASSERT_EQ(OrderStatistic(5, 2, {-1000000000, -999999999, -5, -10, 0}),
            -999999999);
}

TEST(OrderStatisticCorner, KEqualsNMinusOne) {
  ASSERT_EQ(OrderStatistic(5, 4, {8, 3, 10, 1, 6}), 8);
}

TEST(OrderStatisticCorner, PivotIsMinimum) {
  ASSERT_EQ(OrderStatistic(5, 2, {5, 4, 3, 2, 1}), 2);
}

TEST(OrderStatisticCorner, PivotIsMaximum) {
  ASSERT_EQ(OrderStatistic(5, 4, {1, 2, 3, 4, 5}), 4);
}

TEST(OrderStatisticCorner, Ones) {
  ASSERT_EQ(OrderStatistic(5, 2, {1, 1, 1, 1, 1}), 1);
}