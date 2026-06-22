#pragma once

#include <string>
#include <utility>
#include <vector>

std::vector<std::string> AnswerSortedColumnQueries(
    const std::vector<std::vector<int>>& table,
    const std::vector<std::pair<int, int>>& queries);
