#include <gtest/gtest.h>

#include <vector>

#include "task13.hpp"

TEST(CurriculumTest, StandardSchedule) {
  std::vector<std::vector<double>> pairs = {
      {1.0, 3.0}, {2.0, 4.0}, {3.0, 5.0}, {0.0, 2.0}};

  std::vector<std::vector<double>> expected = {{0.0, 2.0}, {2.0, 4.0}};

  ASSERT_EQ(expected, curriculum(pairs.size(), pairs));
}

TEST(CurriculumTest, NoOverlaps) {
  std::vector<std::vector<double>> pairs = {
      {10.0, 11.0}, {11.0, 12.0}, {12.0, 13.0}};

  std::vector<std::vector<double>> expected = {
      {10.0, 11.0}, {11.0, 12.0}, {12.0, 13.0}};

  ASSERT_EQ(expected, curriculum(pairs.size(), pairs));
}

TEST(CurriculumTest, SameStartTime) {
  std::vector<std::vector<double>> pairs = {{1.0, 5.0}, {1.0, 2.0}, {1.0, 3.0}};

  std::vector<std::vector<double>> expected = {{1.0, 2.0}};

  ASSERT_EQ(expected, curriculum(pairs.size(), pairs));
}

TEST(CurriculumTest, EmptySchedule) {
  std::vector<std::vector<double>> pairs = {};
  std::vector<std::vector<double>> expected = {};

  ASSERT_EQ(expected, curriculum(0, pairs));
}
