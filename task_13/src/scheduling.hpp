#include <algorithm>
#include <vector>

struct Lesson {
  double start;
  double end;

  // для тестов
  bool operator==(const Lesson& other) const {
    return start == other.start && end == other.end;
  }
};

std::vector<Lesson> GetSelectedLessons(std::vector<Lesson> lessons) {
  if (lessons.empty()) return lessons;

  sort(lessons.begin(), lessons.end(),
       [](const Lesson& a, const Lesson& b) { return a.end < b.end; });

  std::vector<Lesson> selected_lessons;

  double last_end = -2e9;
  for (int i = 0; i < lessons.size(); ++i) {
    if (lessons[i].start >= last_end) {
      selected_lessons.push_back(lessons[i]);
      last_end = lessons[i].end;
    }
  }
  return selected_lessons;
}