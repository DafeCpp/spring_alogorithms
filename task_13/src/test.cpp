#include <gtest/gtest.h>

#include "solution.hpp"
TEST(schedule, Basic) {
  std::vector<Lesson> lessons = {
      {9.0, 10.0}, {9.3, 10.3}, {10.0, 11.0}, {10.3, 11.3}, {11.0, 12.0}};

  std::vector<Lesson> result = BestSelect(lessons);
  ASSERT_EQ(3, result.size());
  ASSERT_EQ(9.0, result[0].start);
  ASSERT_EQ(10.0, result[0].end);
  ASSERT_EQ(10.0, result[1].start);
  ASSERT_EQ(11.0, result[1].end);
  ASSERT_EQ(11.0, result[2].start);
  ASSERT_EQ(12.0, result[2].end);
}

TEST(schedule, Overlap) {
  std::vector<Lesson> lessons = {{1.0, 5.0}, {1.0, 2.0}, {2.5, 4.0}};

  std::vector<Lesson> result = BestSelect(lessons);
  ASSERT_EQ(2, result.size());
  ASSERT_EQ(1.0, result[0].start);
  ASSERT_EQ(2.0, result[0].end);
  ASSERT_EQ(2.5, result[1].start);
  ASSERT_EQ(4.0, result[1].end);
}

TEST(schedule, Empty) {
  std::vector<Lesson> lessons = {};
  std::vector<Lesson> result = BestSelect(lessons);
  ASSERT_EQ(0, result.size());
}
