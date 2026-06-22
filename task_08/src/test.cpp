#include <gtest/gtest.h>

#include <stdexcept>

#include "order_statistic.h"

TEST(OrderStatisticTest, HandlesMedian) {
  EXPECT_EQ(GetOrderStatistic({7, 10, 4, 3, 20}, 3), 7);
}

TEST(OrderStatisticTest, HandlesMinimum) {
  EXPECT_EQ(GetOrderStatistic({7, 10, 4, 3, 20}, 1), 3);
}

TEST(OrderStatisticTest, HandlesMaximum) {
  EXPECT_EQ(GetOrderStatistic({7, 10, 4, 3, 20}, 5), 20);
}

TEST(OrderStatisticTest, HandlesDuplicates) {
  EXPECT_EQ(GetOrderStatistic({3, 1, 4, 1, 5, 9}, 4), 4);
}

TEST(OrderStatisticTest, HandlesNegativeNumbers) {
  EXPECT_EQ(GetOrderStatistic({-5, 3, -10, 0, 7, -3}, 2), -5);
}

TEST(OrderStatisticTest, HandlesSingleElement) {
  EXPECT_EQ(GetOrderStatistic({42}, 1), 42);
}

TEST(OrderStatisticTest, ThrowsOnNonPositiveOrder) {
  EXPECT_THROW(GetOrderStatistic({1, 2, 3}, 0), std::out_of_range);
  EXPECT_THROW(GetOrderStatistic({1, 2, 3}, -1), std::out_of_range);
}

TEST(OrderStatisticTest, ThrowsWhenOrderExceedsSize) {
  EXPECT_THROW(GetOrderStatistic({1, 2, 3}, 4), std::out_of_range);
  EXPECT_THROW(GetOrderStatistic({}, 1), std::out_of_range);
}
