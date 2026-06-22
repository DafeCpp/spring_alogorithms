#include <gtest/gtest.h>

#include "order_statistic.hpp"

TEST(OrderStatistic, FindsMedian) {
  EXPECT_EQ(KthOrderStatistic({7, 10, 4, 3, 20}, 3), 7);
}

TEST(OrderStatistic, HandlesDuplicates) {
  EXPECT_EQ(KthOrderStatistic({3, 1, 4, 1, 5, 9}, 4), 4);
}
