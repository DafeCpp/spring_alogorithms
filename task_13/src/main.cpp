#include <iostream>

#include "lessons_schedule.hpp"

void PrintResult(const std::vector<Lesson>& schedule) {
  std::cout << schedule.size() << std::endl;
  if (schedule.empty()) return;

  for (const auto& lesson : schedule) {
    std::cout << lesson.start << ' ' << lesson.end << std::endl;
  }
}

int main() {
  int N;
  std::cin >> N;

  std::vector<Lesson> lessons(N);
  for (std::size_t i{0}; i != N; ++i) {
    double start{0};
    double end{0};
    std::cin >> start >> end;
    lessons[i] = Lesson{start, end};
  }

  auto schedule = FindMaxLessonsCount(lessons);
  PrintResult(schedule);
}
