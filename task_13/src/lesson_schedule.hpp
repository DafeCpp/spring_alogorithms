#pragma once

#include <string>
#include <vector>

struct Lesson {
  double start = 0;
  double end = 0;
  std::string start_text;
  std::string end_text;
};

std::vector<Lesson> SelectLessons(std::vector<Lesson> lessons);
