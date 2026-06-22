#include <algorithm>
#include <vector>

std::vector<std::vector<double>> curriculum(
    int N, const std::vector<std::vector<double>>& pairs) {
  std::vector<std::vector<double>> local_pairs = pairs;

  std::sort(local_pairs.begin(), local_pairs.end(),
            [](const std::vector<double>& a, const std::vector<double>& b) {
              if (a[1] != b[1]) {
                return a[1] < b[1];
              }
              return a[0] < b[0];
            });

  std::vector<std::vector<double>> selected_lessons;
  double last_end_time = -1.0;

  for (const auto& lesson : local_pairs) {
    if (lesson[0] >= last_end_time) {
      selected_lessons.push_back(lesson);
      last_end_time = lesson[1];
    }
  }

  std::sort(selected_lessons.begin(), selected_lessons.end(),
            [](const std::vector<double>& a, const std::vector<double>& b) {
              return a[0] < b[0];
            });

  return selected_lessons;
}
