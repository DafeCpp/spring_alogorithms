#include <iostream>

#include "scheduling.hpp"

int main() {
  int n;
  std::cin >> n;

  std::vector<Lesson> lessons(n);
  for (int i = 0; i < n; ++i) {
    double start, end;
    std::cin >> start >> end;
    lessons[i] = {start, end};
  }

  std::vector<Lesson> selected_lessons = GetSelectedLessons(lessons);
  std::cout << selected_lessons.size() << "\n";

  for (Lesson lesson : selected_lessons)
    std::cout << lesson.start << " " << lesson.end << "\n";
}
