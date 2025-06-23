
#include <gtest/gtest.h>

#include "fish_days.hpp"

TEST(FishDays, OneDay) {
  std::vector<int> expected = {1};
  ASSERT_EQ(calculate_fish_days(1, 1, {5.0}), expected);
}

TEST(FishDays, CheapFishWeek) {
  std::vector<double> prices = {5, 5, 1, 5, 5, 5, 5};
  std::vector<int> expected = {1, 1, 3, 0, 0, 1, 1};
  ASSERT_EQ(calculate_fish_days(7, 3, prices), expected);
}

TEST(FishDays, AllAtOne) {
  std::vector<double> prices = {8, 9, 10, 15, 20};
  std::vector<int> expected = {5, 0, 0, 0, 0};
  ASSERT_EQ(calculate_fish_days(5, 5, prices), expected);
}

TEST(FishDays, EveryDay) {
  std::vector<double> prices = {10, 8, 6, 4, 2};
  std::vector<int> expected = {1, 1, 1, 1, 1};
  ASSERT_EQ(calculate_fish_days(5, 2, prices), expected);
}

TEST(FishDays, AnotherEveryDay) {
  std::vector<double> prices(10, 5.0);
  std::vector<int> expected(10, 1);
  ASSERT_EQ(calculate_fish_days(10, 3, prices), expected);
}

TEST(FishDays, Empty) {
  std::vector<int> expected;
  ASSERT_EQ(calculate_fish_days(0, 3, {}), expected);
}

TEST(FishDays, K_is_One) {
  std::vector<double> prices = {3, 1, 4, 1, 5};
  std::vector<int> expected = {1, 1, 1, 1, 1};
  ASSERT_EQ(calculate_fish_days(5, 1, prices), expected);
}

TEST(FishDays, Simple) {
  std::vector<double> prices = {7, 3, 8, 2, 5, 1, 9};
  std::vector<int> expected = {1, 2, 0, 2, 0, 2, 0};
  ASSERT_EQ(calculate_fish_days(7, 4, prices), expected);
}