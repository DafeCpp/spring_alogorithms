#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(DailyTemperaturesBasic, Example1) {
  std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};

  ASSERT_EQ(TopologySort(8, {73, 74, 75, 71, 69, 72, 76, 73}), expected);
}

TEST(DailyTemperaturesBasic, Example2) {
  std::vector<int> expected = {1, 1, 1, 0};

  ASSERT_EQ(TopologySort(4, {30, 40, 50, 60}), expected);
}

TEST(DailyTemperaturesBasic, Example3) {
  std::vector<int> expected = {0, 0, 0, 0};

  ASSERT_EQ(TopologySort(4, {60, 50, 40, 30}), expected);
}

TEST(DailyTemperaturesBasic, SingleDay) {
  std::vector<int> expected = {0};

  ASSERT_EQ(TopologySort(1, {42}), expected);
}

TEST(DailyTemperaturesBasic, TwoDaysWarmer) {
  std::vector<int> expected = {1, 0};

  ASSERT_EQ(TopologySort(2, {10, 20}), expected);
}

TEST(DailyTemperaturesBasic, TwoDaysColder) {
  std::vector<int> expected = {0, 0};

  ASSERT_EQ(TopologySort(2, {20, 10}), expected);
}

TEST(DailyTemperaturesBasic, WarmerAfterSeveralDays) {
  std::vector<int> expected = {3, 2, 1, 0};

  ASSERT_EQ(TopologySort(4, {10, 9, 8, 20}), expected);
}

TEST(DailyTemperaturesBasic, AlternatingTemperatures) {
  std::vector<int> expected = {1, 0, 1, 0};

  ASSERT_EQ(TopologySort(4, {10, 20, 10, 20}), expected);
}

TEST(DailyTemperaturesBasic, NegativeTemperatures) {
  std::vector<int> expected = {1, 1, 0};

  ASSERT_EQ(TopologySort(3, {-10, -5, 0}), expected);
}

TEST(DailyTemperaturesBasic, PlateauThenWarmer) {
  std::vector<int> expected = {3, 2, 1, 0};

  ASSERT_EQ(TopologySort(4, {10, 10, 10, 20}), expected);
}

TEST(DailyTemperaturesCorner, AllEqual) {
  std::vector<int> expected = {0, 0, 0, 0, 0};

  ASSERT_EQ(TopologySort(5, {7, 7, 7, 7, 7}), expected);
}

TEST(DailyTemperaturesCorner, EqualValuesNotWarmer) {
  std::vector<int> expected = {0, 0, 0};

  ASSERT_EQ(TopologySort(3, {10, 10, 10}), expected);
}

TEST(DailyTemperaturesCorner, EqualThenWarmer) {
  std::vector<int> expected = {2, 1, 0};

  ASSERT_EQ(TopologySort(3, {10, 10, 11}), expected);
}

TEST(DailyTemperaturesCorner, PeakAtBeginning) {
  std::vector<int> expected = {0, 0, 0, 0};

  ASSERT_EQ(TopologySort(4, {100, 90, 80, 70}), expected);
}

TEST(DailyTemperaturesCorner, PeakAtEnd) {
  std::vector<int> expected = {1, 1, 1, 1, 0};

  ASSERT_EQ(TopologySort(5, {1, 2, 3, 4, 100}), expected);
}

TEST(DailyTemperaturesCorner, LargeJump) {
  std::vector<int> expected = {4, 3, 2, 1, 0};

  ASSERT_EQ(TopologySort(5, {1, 1, 1, 1, 100}), expected);
}

TEST(DailyTemperaturesCorner, ZigZag) {
  std::vector<int> expected = {2, 1, 2, 1, 0};

  ASSERT_EQ(TopologySort(5, {10, 5, 20, 15, 25}), expected);
}

TEST(DailyTemperaturesCorner, RepeatedPeaks) {
  std::vector<int> expected = {0, 1, 0, 0};

  ASSERT_EQ(TopologySort(4, {30, 20, 30, 20}), expected);
}

TEST(DailyTemperaturesCorner, LongWait) {
  std::vector<int> expected = {5, 4, 3, 2, 1, 0};

  ASSERT_EQ(TopologySort(6, {50, 49, 48, 47, 46, 100}), expected);
}

TEST(DailyTemperaturesCorner, EmptyArray) {
  std::vector<int> expected;

  ASSERT_EQ(TopologySort(0, {}), expected);
}