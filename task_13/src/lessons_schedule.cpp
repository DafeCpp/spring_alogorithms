#include "lessons_schedule.hpp"

#include <algorithm>
#include <limits>

std::vector<Lesson> FindMaxLessonsCount(std::vector<Lesson> lessons) {
  std::sort(
      lessons.begin(), lessons.end(),
      [](const Lesson& lhs, const Lesson& rhs) { return lhs.end < rhs.end; });

  double last_end = -std::numeric_limits<double>::infinity();
  std::vector<Lesson> result_schedule;
  for (const auto& lesson : lessons) {
    if (lesson.start >= last_end) {
      last_end = lesson.end;
      result_schedule.push_back(lesson);
    }
  }
  return result_schedule;
}