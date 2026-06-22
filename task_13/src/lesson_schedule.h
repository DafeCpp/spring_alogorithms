#pragma once

#include <cstddef>
#include <vector>

struct Lesson {
  double start;
  double end;
};

std::vector<std::size_t> SelectMaximumLessons(
    const std::vector<Lesson>& lessons);
