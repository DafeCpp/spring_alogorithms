#include <iostream>
#include <string>
#include <vector>

#include "lesson_schedule.h"

int main() {
  int count;
  std::cin >> count;

  std::vector<Lesson> lessons;
  lessons.reserve(count);
  std::vector<std::string> start_text(count);
  std::vector<std::string> end_text(count);

  for (int i = 0; i < count; ++i) {
    std::cin >> start_text[i] >> end_text[i];
    lessons.push_back({std::stod(start_text[i]), std::stod(end_text[i])});
  }

  const std::vector<Lesson> selected = SelectMaximumLessons(lessons);

  std::cout << selected.size();
  std::vector<bool> used(count, false);
  for (const Lesson& lesson : selected) {
    for (int i = 0; i < count; ++i) {
      if (!used[i] && lessons[i].start == lesson.start &&
          lessons[i].end == lesson.end) {
        used[i] = true;
        std::cout << '\n' << start_text[i] << ' ' << end_text[i];
        break;
      }
    }
  }

  return 0;
}
