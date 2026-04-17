#include "lesson_schedule.h"

#include <algorithm>

std::vector<Lesson> SelectMaximumLessons(const std::vector<Lesson>& lessons) {
  std::vector<Lesson> sorted = lessons;
  std::ranges::sort(sorted, [](const Lesson& lhs, const Lesson& rhs) {
    if (lhs.end != rhs.end) {
      return lhs.end < rhs.end;
    }
    return lhs.start < rhs.start;
  });

  std::vector<Lesson> selected;
  double current_end = -1e18;
  for (const Lesson& lesson : sorted) {
    if (lesson.start >= current_end) {
      selected.push_back(lesson);
      current_end = lesson.end;
    }
  }

  return selected;
}
