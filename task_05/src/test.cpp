
#include <gtest/gtest.h>

#include <vector>

#include "task5.hpp"

TEST(DailyTemp, Example1) {
  std::vector<int> t{73, 74, 75, 71, 69, 72, 76, 73};
  auto r = DaysBeforeWarming((int)t.size(), t);
  std::vector<int> expect{1, 1, 4, 2, 1, 1, 0, 0};
  ASSERT_EQ(expect, r);
}

TEST(DailyTemp, Increasing) {
  std::vector<int> t{30, 40, 50, 60};
  auto r = DaysBeforeWarming((int)t.size(), t);
  std::vector<int> expect{1, 1, 1, 0};
  ASSERT_EQ(expect, r);
}

TEST(DailyTemp, Decreasing) {
  std::vector<int> t{60, 50, 40, 30};
  auto r = DaysBeforeWarming((int)t.size(), t);
  std::vector<int> expect{0, 0, 0, 0};
  ASSERT_EQ(expect, r);
}

TEST(DailyTemp, EqualTemps) {
  std::vector<int> t{50, 50, 50};
  auto r = DaysBeforeWarming((int)t.size(), t);
  std::vector<int> expect{0, 0, 0};
  ASSERT_EQ(expect, r);
}

TEST(DailyTemp, ImmediateWarm) {
  std::vector<int> t{50, 51};
  auto r = DaysBeforeWarming((int)t.size(), t);
  std::vector<int> expect{1, 0};
  ASSERT_EQ(expect, r);
}

TEST(DailyTemp, SingleDay) {
  std::vector<int> t{42};
  auto r = DaysBeforeWarming((int)t.size(), t);
  std::vector<int> expect{0};
  ASSERT_EQ(expect, r);
}

TEST(DailyTemp, Complex) {
  std::vector<int> t{5, 3, 8, 4, 6, 2, 7};
  auto r = DaysBeforeWarming((int)t.size(), t);
  std::vector<int> expect{2, 1, 0, 1, 2, 1, 0};
  ASSERT_EQ(expect, r);
}
