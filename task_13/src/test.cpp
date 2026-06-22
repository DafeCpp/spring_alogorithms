#include <gtest/gtest.h>

#include "lesson_schedule.hpp"

TEST(LessonSchedule, HandlesEmptyInput) {
  EXPECT_TRUE(SelectLessons({}).empty());
}

TEST(LessonSchedule, HandlesSingleLesson) {
  const auto selected = SelectLessons({{8, 9, "8", "9"}});
  ASSERT_EQ(selected.size(), 1);
  EXPECT_EQ(selected[0].start_text, "8");
  EXPECT_EQ(selected[0].end_text, "9");
}

TEST(LessonSchedule, SelectsMaximumNonOverlappingSet) {
  const auto selected = SelectLessons({{9, 10, "9", "10"},
                                       {9.3, 10.3, "9.3", "10.3"},
                                       {10, 11, "10", "11"},
                                       {10.3, 11.3, "10.3", "11.3"},
                                       {11, 12, "11", "12"}});
  ASSERT_EQ(selected.size(), 3);
  EXPECT_EQ(selected[0].start_text, "9");
  EXPECT_EQ(selected[1].start_text, "10");
  EXPECT_EQ(selected[2].start_text, "11");
}

TEST(LessonSchedule, HandlesAllOverlappingLessons) {
  const auto selected = SelectLessons(
      {{9, 12, "9", "12"}, {10, 13, "10", "13"}, {11, 14, "11", "14"}});
  ASSERT_EQ(selected.size(), 1);
  EXPECT_EQ(selected[0].start_text, "9");
  EXPECT_EQ(selected[0].end_text, "12");
}

TEST(LessonSchedule, HandlesNoOverlappingLessons) {
  const auto selected = SelectLessons({{8, 9, "8", "9"},
                                       {10, 11, "10", "11"},
                                       {12, 13, "12", "13"},
                                       {14, 15, "14", "15"}});
  ASSERT_EQ(selected.size(), 4);
  EXPECT_EQ(selected[0].start_text, "8");
  EXPECT_EQ(selected[1].start_text, "10");
  EXPECT_EQ(selected[2].start_text, "12");
  EXPECT_EQ(selected[3].start_text, "14");
}
