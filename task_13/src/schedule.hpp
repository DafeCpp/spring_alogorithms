#pragma once

#include <vector>
#include <utility>

struct Lesson {
    double start;
    double end;
};

std::vector<Lesson> selectLessons(const std::vector<Lesson>& lessons);