#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "task13.hpp"

TEST(Func13, Example) {
  std::vector<std::pair<double, double>> lessons = {
      {9, 10}, {9.3, 10.3}, {10, 11}, {10.3, 11.3}, {11, 12}};

  auto res = func((int)lessons.size(), lessons);
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

  auto res = func((int)lessons.size(), lessons);
  ASSERT_EQ(res.size(), 4u);
  for (size_t i = 0; i < res.size(); ++i) {
    EXPECT_DOUBLE_EQ(res[i].first, lessons[i].first);
    EXPECT_DOUBLE_EQ(res[i].second, lessons[i].second);
  }
}

TEST(Func13, AllOverlap) {
  std::vector<std::pair<double, double>> lessons = {
      {9, 12}, {10, 13}, {11, 14}};

  auto res = func((int)lessons.size(), lessons);
  ASSERT_EQ(res.size(), 1u);
  EXPECT_DOUBLE_EQ(res[0].first, 9);
  EXPECT_DOUBLE_EQ(res[0].second, 12);
}

TEST(Func13, SingleLesson) {
  std::vector<std::pair<double, double>> lessons = {{8, 9}};

  auto res = func((int)lessons.size(), lessons);
  ASSERT_EQ(res.size(), 1u);
  EXPECT_DOUBLE_EQ(res[0].first, 8);
  EXPECT_DOUBLE_EQ(res[0].second, 9);
}

TEST(Func13, BackToBack) {
  std::vector<std::pair<double, double>> lessons = {
      {9, 9.5}, {9.5, 10}, {10, 10.5}, {10.5, 11}};

  auto res = func((int)lessons.size(), lessons);
  ASSERT_EQ(res.size(), 4u);
  EXPECT_DOUBLE_EQ(res[0].first, 9);
  EXPECT_DOUBLE_EQ(res[0].second, 9.5);
  EXPECT_DOUBLE_EQ(res[1].first, 9.5);
  EXPECT_DOUBLE_EQ(res[1].second, 10);
  EXPECT_DOUBLE_EQ(res[2].first, 10);
  EXPECT_DOUBLE_EQ(res[2].second, 10.5);
  EXPECT_DOUBLE_EQ(res[3].first, 10.5);
  EXPECT_DOUBLE_EQ(res[3].second, 11);
}

TEST(Func13, EmptyInput) {
  std::vector<std::pair<double, double>> lessons;

  auto res = func(0, lessons);
  ASSERT_EQ(res.size(), 0u);
}

TEST(Func13, UnsortedInput) {
  std::vector<std::pair<double, double>> lessons = {
      {11, 12}, {9, 10}, {10, 11}, {9.3, 10.3}, {10.3, 11.3}};

  auto res = func((int)lessons.size(), lessons);
  ASSERT_EQ(res.size(), 3u);
  EXPECT_DOUBLE_EQ(res[0].first, 9);
  EXPECT_DOUBLE_EQ(res[0].second, 10);
  EXPECT_DOUBLE_EQ(res[1].first, 10);
  EXPECT_DOUBLE_EQ(res[1].second, 11);
  EXPECT_DOUBLE_EQ(res[2].first, 11);
  EXPECT_DOUBLE_EQ(res[2].second, 12);
}