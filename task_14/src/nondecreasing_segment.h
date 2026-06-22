#pragma once

#include <string>
#include <utility>
#include <vector>

std::vector<std::string> CanReachNonDecreasingSegment(
    const std::vector<std::vector<int>>& table,
    const std::vector<std::pair<int, int>>& queries);
