#pragma once

#include <utility>
#include <vector>

std::vector<bool> CanReachNonDecreasingSegment(
    const std::vector<std::vector<int>>& matrix,
    const std::vector<std::pair<int, int>>& queries);