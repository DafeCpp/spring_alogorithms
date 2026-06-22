#include "lesson_schedule.hpp"

#include <algorithm>
#include <cmath>

constexpr double kEps = 1e-9;

static bool EqualTime(double lhs, double rhs) {
  return std::abs(lhs - rhs) < kEps;
}

std::vector<Lesson> SelectLessons(std::vector<Lesson> lessons) {
  std::sort(lessons.begin(), lessons.end(),
            [](const Lesson& lhs, const Lesson& rhs) {
              if (EqualTime(lhs.end, rhs.end)) {
                return lhs.start < rhs.start;
              }
              return lhs.end < rhs.end;
            });

  std::vector<Lesson> selected;
  double last_end = -1e100;
  for (const Lesson& lesson : lessons) {
    if (lesson.start + kEps >= last_end) {
      selected.push_back(lesson);
      last_end = lesson.end;
    }
  }

  std::sort(selected.begin(), selected.end(),
            [](const Lesson& lhs, const Lesson& rhs) {
              if (EqualTime(lhs.start, rhs.start)) {
                return lhs.end < rhs.end;
              }
              return lhs.start < rhs.start;
            });

  return selected;
}
