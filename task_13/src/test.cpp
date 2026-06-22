
#include <gtest/gtest.h>

#include <vector>

#include "SelectMaxNonOverlappingIntervals.h"

TEST(Func13, Example) {
  std::vector<std::pair<double, double>> lessons = {
      {9, 10}, {9.3, 10.3}, {10, 11}, {10.3, 11.3}, {11, 12}};
  auto res = SelectMaxNonOverlappingIntervals(lessons);
  ASSERT_EQ(res.size(), 3u);
  EXPECT_DOUBLE_EQ(res[0].first, 9);
  EXPECT_DOUBLE_EQ(res[0].second, 10);
  EXPECT_DOUBLE_EQ(res[1].first, 10);
  EXPECT_DOUBLE_EQ(res[1].second, 11);
  EXPECT_DOUBLE_EQ(res[2].first, 11);
  EXPECT_DOUBLE_EQ(res[2].second, 12);
}

TEST(Func13, NoOverlap) {
  std::vector<std::pair<double, double>> lessons = {
      {8, 9}, {10, 11}, {12, 13}, {14, 15}};
  auto res = SelectMaxNonOverlappingIntervals(lessons);
  ASSERT_EQ(res.size(), 4u);
  for (size_t i = 0; i < res.size(); ++i) {
    EXPECT_DOUBLE_EQ(res[i].first, lessons[i].first);
    EXPECT_DOUBLE_EQ(res[i].second, lessons[i].second);
  }
}

TEST(Func13, AllOverlap) {
  std::vector<std::pair<double, double>> lessons = {
      {9, 12}, {10, 13}, {11, 14}};
  auto res = SelectMaxNonOverlappingIntervals(lessons);
  ASSERT_EQ(res.size(), 1u);
  EXPECT_DOUBLE_EQ(res[0].first, 9);
  EXPECT_DOUBLE_EQ(res[0].second, 12);
}

TEST(Func13, SingleLesson) {
  std::vector<std::pair<double, double>> lessons = {{8, 9}};
  auto res = SelectMaxNonOverlappingIntervals(lessons);
  ASSERT_EQ(res.size(), 1u);
  EXPECT_DOUBLE_EQ(res[0].first, 8);
  EXPECT_DOUBLE_EQ(res[0].second, 9);
}
