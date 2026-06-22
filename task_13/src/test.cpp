#include <gtest/gtest.h>

#include "lesson_schedule.h"

TEST(LessonScheduleTest, HandlesExample) {
  const std::vector<Lesson> lessons = {
      {9.0, 10.0}, {9.3, 10.3}, {10.0, 11.0}, {10.3, 11.3}, {11.0, 12.0},
  };
  const std::vector<std::size_t> result = SelectMaximumLessons(lessons);

  ASSERT_EQ(result.size(), 3);
  EXPECT_EQ(lessons[result[0]].start, 9.0);
  EXPECT_EQ(lessons[result[1]].start, 10.0);
  EXPECT_EQ(lessons[result[2]].start, 11.0);
}

TEST(LessonScheduleTest, HandlesAllOverlap) {
  const std::vector<Lesson> lessons = {
      {9.0, 12.0},
      {10.0, 13.0},
      {11.0, 14.0},
  };
  const std::vector<std::size_t> result = SelectMaximumLessons(lessons);

  ASSERT_EQ(result.size(), 1);
  EXPECT_EQ(lessons[result[0]].start, 9.0);
}

TEST(LessonScheduleTest, HandlesNoOverlap) {
  const std::vector<Lesson> lessons = {
      {8.0, 9.0},
      {10.0, 11.0},
      {12.0, 13.0},
  };
  const std::vector<std::size_t> result = SelectMaximumLessons(lessons);

  ASSERT_EQ(result.size(), 3);
}

TEST(LessonScheduleTest, ReturnsCorrectIndexForDuplicateLessons) {
  const std::vector<Lesson> lessons = {
      {9.0, 10.0},
      {9.0, 10.0},
      {10.0, 11.0},
  };
  const std::vector<std::size_t> result = SelectMaximumLessons(lessons);

  ASSERT_EQ(result.size(), 2);
  EXPECT_NE(result[0], result[1]);
}
