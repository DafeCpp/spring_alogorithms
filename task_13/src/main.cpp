#include <iostream>
#include <vector>

#include "lesson_schedule.h"

int main() {
  int count;
  std::cin >> count;

  std::vector<Lesson> lessons;
  lessons.reserve(count);

  for (int i = 0; i < count; ++i) {
    Lesson lesson;
    std::cin >> lesson.start_text >> lesson.end_text;
    lesson.start = std::stod(lesson.start_text);
    lesson.end = std::stod(lesson.end_text);
    lessons.push_back(lesson);
  }

  const std::vector<Lesson> selected = SelectMaximumLessons(lessons);
  std::cout << selected.size();
  for (const Lesson& lesson : selected) {
    std::cout << '\n' << lesson.start_text << ' ' << lesson.end_text;
  }

  return 0;
}
