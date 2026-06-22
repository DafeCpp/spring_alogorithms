#include <iostream>

#include "solution.hpp"

int main() {
  int N;
  if (std::cin >> N) {
    std::vector<Lesson> lessons(N);
    for (int i = 0; i < N; i++) {
      std::cin >> lessons[i].start >> lessons[i].end;
    }
    std::vector<Lesson> result = BestSelect(lessons);
    std::cout << result.size() << std::endl;
    for (const auto& lesson : result) {
      std::cout << lesson.start << " " << lesson.end << std::endl;
    }
  }
  return 0;
}
