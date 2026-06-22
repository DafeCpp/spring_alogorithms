#include <iostream>
#include <string>
#include <vector>

#include "lesson_schedule.hpp"

int main() {
  int count = 0;
  std::cin >> count;

  std::vector<Lesson> lessons(count);
  for (Lesson& lesson : lessons) {
    std::cin >> lesson.start_text >> lesson.end_text;
    lesson.start = std::stod(lesson.start_text);
    lesson.end = std::stod(lesson.end_text);
  }

  const auto selected = SelectLessons(lessons);
  std::cout << selected.size();
  for (const Lesson& lesson : selected) {
    std::cout << '\n' << lesson.start_text << ' ' << lesson.end_text;
  }
}
