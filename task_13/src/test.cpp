#include <gtest/gtest.h>

#include "lesson_schedule.h"

TEST(LessonScheduleTest, HandlesExample) {
  const std::vector<Lesson> result = SelectMaximumLessons({
      {9.0, 10.0, "9", "10"},
      {9.3, 10.3, "9.3", "10.3"},
      {10.0, 11.0, "10", "11"},
      {10.3, 11.3, "10.3", "11.3"},
      {11.0, 12.0, "11", "12"},
  });

  ASSERT_EQ(result.size(), 3);
  EXPECT_EQ(result[0].start_text, "9");
  EXPECT_EQ(result[1].start_text, "10");
  EXPECT_EQ(result[2].start_text, "11");
}

TEST(LessonScheduleTest, HandlesAllOverlap) {
  const std::vector<Lesson> result = SelectMaximumLessons({
      {9.0, 12.0, "9", "12"},
      {10.0, 13.0, "10", "13"},
      {11.0, 14.0, "11", "14"},
  });

  ASSERT_EQ(result.size(), 1);
  EXPECT_EQ(result[0].start_text, "9");
}

TEST(LessonScheduleTest, HandlesNoOverlap) {
  const std::vector<Lesson> result = SelectMaximumLessons({
      {8.0, 9.0, "8", "9"},
      {10.0, 11.0, "10", "11"},
      {12.0, 13.0, "12", "13"},
  });

  ASSERT_EQ(result.size(), 3);
}
