#include "solution.hpp"

#include <algorithm>

bool compare(const Lesson& a, const Lesson& b) {
  if (std::abs(a.end - b.end) < 1e-9) return a.start < b.start;
  return a.end < b.end;
}

std::vector<Lesson> BestSelect(std::vector<Lesson> lessons) {
  std::sort(lessons.begin(), lessons.end(), compare);

  std::vector<Lesson> selected;
  double cur_end = -1.;
  for (const auto& lesson : lessons) {
    if (lesson.start >= cur_end) {
      selected.push_back(lesson);
      cur_end = lesson.end;
    }
  }
  return selected;
}