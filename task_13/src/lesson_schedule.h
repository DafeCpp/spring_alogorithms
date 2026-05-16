#pragma once

#include <vector>

struct Lesson {
  double start;
  double end;
};

std::vector<Lesson> SelectMaximumLessons(const std::vector<Lesson>& lessons);
