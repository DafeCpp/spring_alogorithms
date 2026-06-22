#pragma once

#include <optional>
#include <utility>
#include <vector>

std::optional<std::pair<int, int>> FindPairWithSum(
    const std::vector<int>& numbers, int target);
