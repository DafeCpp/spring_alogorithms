#include "lesson_schedule.h"

#include <algorithm>
#include <numeric>

std::vector<std::size_t> SelectMaximumLessons(
    const std::vector<Lesson>& lessons) {
  std::vector<std::size_t> order(lessons.size());
  std::iota(order.begin(), order.end(), 0);
  std::ranges::sort(order, [&lessons](std::size_t lhs, std::size_t rhs) {
    if (lessons[lhs].end != lessons[rhs].end) {
      return lessons[lhs].end < lessons[rhs].end;
    }
    return lessons[lhs].start < lessons[rhs].start;
  });

  std::vector<std::size_t> selected;
  double current_end = -1e18;
  for (const std::size_t index : order) {
    if (lessons[index].start >= current_end) {
      selected.push_back(index);
      current_end = lessons[index].end;
    }
  }

  return selected;
}
