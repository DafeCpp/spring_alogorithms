
#include <gtest/gtest.h>

#include "warming_func.hpp"

TEST(Warm, Simple) {
  std ::vector<int> temperature = {73, 74, 75, 71, 69, 72, 76, 73};
  std ::vector<int> ans = {1, 1, 4, 2, 1, 1, 0, 0};
  ASSERT_EQ(Warming(temperature), ans);
}

TEST(Warm, Stable) {
  std ::vector<int> temperature = {30, 20, 10};
  std ::vector<int> ans = {0, 0, 0};
  ASSERT_EQ(Warming(temperature), ans);
}

TEST(Warm, OneDay) {
  std ::vector<int> temperature = {50};
  std ::vector<int> ans = {0};
  ASSERT_EQ(Warming(temperature), ans);
}

TEST(Warm, Empty) {
  std ::vector<int> temperature = {};
  std ::vector<int> ans = {};
  ASSERT_EQ(Warming(temperature), ans);
}

TEST(Warm, SameTemperature) {
  std ::vector<int> temperature = {10, 10, 10, 10};
  std ::vector<int> ans = {0, 0, 0, 0};
  ASSERT_EQ(Warming(temperature), ans);
}

TEST(Warm, Negative) {
  std ::vector<int> temperature = {-10, -5, -20};
  std ::vector<int> ans = {1, 0, 0};
  ASSERT_EQ(Warming(temperature), ans);
}

TEST(Warm, BigDiff) {
  std ::vector<int> temperature = {0, -10, 100, 5, 1000};
  std ::vector<int> ans = {2, 1, 2, 1, 0};
  ASSERT_EQ(Warming(temperature), ans);
}
