#include "SelectMaxNonOverlappingIntervals.h"

#include <algorithm>
#include <utility>
#include <vector>

std::vector<std::pair<double, double>> SelectMaxNonOverlappingIntervals(
    const std::vector<std::pair<double, double>>& lessons) {
  std::vector<std::pair<double, double>> sorted_lessons = lessons;
  std::sort(sorted_lessons.begin(), sorted_lessons.end(),
            [](const std::pair<double, double>& a,
               const std::pair<double, double>& b) {
              if (a.second != b.second) {
                return a.second < b.second;
              }
              return a.first < b.first;
            });

  std::vector<std::pair<double, double>> selected;
  double last_end_time = -1.0;

  for (const auto& lesson : sorted_lessons) {
    if (lesson.first >= last_end_time) {
      selected.push_back(lesson);
      last_end_time = lesson.second;
    }
  }
  return selected;
}