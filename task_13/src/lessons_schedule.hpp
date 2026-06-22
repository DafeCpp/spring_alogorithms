#pragma once

#include <cmath>
#include <vector>

struct Lesson {
  double start;
  double end;

  bool operator==(const Lesson& other) const {
    return std::abs(other.start - start) < 1e-9 &&
           std::abs(other.end - end) < 1e-9;
  }
};

std::vector<Lesson> FindMaxLessonsCount(std::vector<Lesson> lessons);