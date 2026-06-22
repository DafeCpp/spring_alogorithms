#include "schedule.hpp"
#include <algorithm>

std::vector<Lesson> selectLessons(const std::vector<Lesson>& lessons) {
    if (lessons.empty()) {
        return {};
    }
    
    std::vector<Lesson> sorted = lessons;
    std::sort(sorted.begin(), sorted.end(), 
              [](const Lesson& a, const Lesson& b) {
                  return a.end < b.end;
              });
    
    std::vector<Lesson> result;
    result.push_back(sorted[0]);
    
    for (size_t i = 1; i < sorted.size(); ++i) {
        if (sorted[i].start >= result.back().end) {
            result.push_back(sorted[i]);
        }
    }
    
    return result;
}