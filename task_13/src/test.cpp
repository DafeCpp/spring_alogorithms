#include <gtest/gtest.h>

#include "scheduling.hpp"

TEST(Test, Simple) {
  std::vector<Lesson> v1 = {{9, 12}, {10, 13}, {11, 14}};
  std::vector<Lesson> expected1 = {{9, 12}};
  ASSERT_EQ(GetSelectedLessons(v1), expected1);

  // не пересекающиеся
  std::vector<Lesson> v2 = {{9, 10}, {10, 11}, {11, 12}};
  std::vector<Lesson> expected2 = {{9, 10}, {10, 11}, {11, 12}};
  ASSERT_EQ(GetSelectedLessons(v2), expected2);

  // пересекающиеся
  std::vector<Lesson> v3 = {{9, 12}, {10, 13}, {11, 14}};
  std::vector<Lesson> expected3 = {{9, 12}};
  ASSERT_EQ(GetSelectedLessons(v3), expected3);

  // с вложенными интервалами
  std::vector<Lesson> v4 = {{8, 17}, {9, 16}, {10, 15}, {11, 14}, {12, 13}};
  std::vector<Lesson> expected4 = {{12, 13}};
  ASSERT_EQ(GetSelectedLessons(v4), expected4);

  // вещественные числа
  std::vector<Lesson> v5 = {{9.1, 9.5}, {9.3, 9.8}, {9.5, 10.2}, {9.8, 10}};
  std::vector<Lesson> expected5 = {{9.1, 9.5}, {9.8, 10}};
  ASSERT_EQ(GetSelectedLessons(v5), expected5);
}

TEST(Test, Empty) {
  std::vector<Lesson> v = {};
  std::vector<Lesson> expected = {};
  ASSERT_EQ(GetSelectedLessons(v), expected);
}

TEST(Test, SingleLesson) {
  std::vector<Lesson> v = {{9, 12}};
  std::vector<Lesson> expected = {{9, 12}};
  ASSERT_EQ(GetSelectedLessons(v), expected);
}

TEST(Test, SameEnd) {
  // Одинаковое время окончания
  std::vector<Lesson> v = {{9, 12}, {10, 12}, {11, 12}};
  std::vector<Lesson> expected = {{9, 12}};
  ASSERT_EQ(GetSelectedLessons(v), expected);
}
