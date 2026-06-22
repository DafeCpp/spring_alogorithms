#include <cstddef>
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

  const std::vector<std::size_t> selected = SelectMaximumLessons(lessons);

  std::cout << selected.size();
  for (const std::size_t index : selected) {
    std::cout << '\n' << start_text[index] << ' ' << end_text[index];
  }

  return 0;
}
