#pragma once

#include <string>
#include <vector>

struct Lesson {
  double start;
  double end;
  std::string start_text;
  std::string end_text;
};

std::vector<Lesson> SelectMaximumLessons(const std::vector<Lesson>& lessons);
