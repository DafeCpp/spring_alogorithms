#include <gtest/gtest.h>

#include "lessons_schedule.hpp"

TEST(ScheduleLessonsBasic, Example) {
  std::vector<Lesson> expected = {{9.0, 10.0}, {10.0, 11.0}, {11.0, 12.0}};

  ASSERT_EQ(
      FindMaxLessonsCount(
          {{9.0, 10.0}, {9.3, 10.3}, {10.0, 11.0}, {10.3, 11.3}, {11.0, 12.0}}),
      expected);
}

TEST(ScheduleLessonsBasic, SingleLesson) {
  std::vector<Lesson> expected = {{1.0, 2.0}};

  ASSERT_EQ(FindMaxLessonsCount({{1.0, 2.0}}), expected);
}

TEST(ScheduleLessonsBasic, NoOverlap) {
  std::vector<Lesson> expected = {{1.0, 2.0}, {2.0, 3.0}, {3.0, 4.0}};

  ASSERT_EQ(FindMaxLessonsCount({{1.0, 2.0}, {2.0, 3.0}, {3.0, 4.0}}),
            expected);
}

TEST(ScheduleLessonsBasic, FullOverlap) {
  std::vector<Lesson> expected = {{4.0, 7.0}};

  ASSERT_EQ(
      FindMaxLessonsCount({{1.0, 10.0}, {2.0, 9.0}, {3.0, 8.0}, {4.0, 7.0}}),
      expected);
}

TEST(ScheduleLessonsBasic, LongIntervalVsShort) {
  std::vector<Lesson> expected = {{2.0, 3.0}, {3.0, 4.0}, {4.0, 5.0}};

  ASSERT_EQ(
      FindMaxLessonsCount({{1.0, 10.0}, {2.0, 3.0}, {3.0, 4.0}, {4.0, 5.0}}),
      expected);
}

TEST(ScheduleLessonsBasic, UnsortedInput) {
  std::vector<Lesson> expected = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};

  ASSERT_EQ(FindMaxLessonsCount({{5.0, 6.0}, {1.0, 2.0}, {3.0, 4.0}}),
            expected);
}

TEST(ScheduleLessonsBasic, DecimalTimes) {
  std::vector<Lesson> expected = {{1.1, 2.2}, {2.2, 3.3}};

  ASSERT_EQ(FindMaxLessonsCount({{1.1, 2.2}, {2.2, 3.3}, {2.0, 4.0}}),
            expected);
}

TEST(ScheduleLessonsBasic, TouchingIntervals) {
  std::vector<Lesson> expected = {
      {1.0, 2.0}, {2.0, 3.0}, {3.0, 4.0}, {4.0, 5.0}};

  ASSERT_EQ(
      FindMaxLessonsCount({{1.0, 2.0}, {2.0, 3.0}, {3.0, 4.0}, {4.0, 5.0}}),
      expected);
}

TEST(ScheduleLessonsCorner, EmptyInput) {
  std::vector<Lesson> expected;

  ASSERT_EQ(FindMaxLessonsCount({}), expected);
}

TEST(ScheduleLessonsCorner, SameIntervals) {
  std::vector<Lesson> expected = {{1.0, 2.0}};

  ASSERT_EQ(FindMaxLessonsCount({{1.0, 2.0}, {1.0, 2.0}, {1.0, 2.0}}),
            expected);
}