#pragma once

#include <vector>

struct Lesson {
  double start;
  double end;
};

std::vector<Lesson> BestSelect(std::vector<Lesson> lessons);