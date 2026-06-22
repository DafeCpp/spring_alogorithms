#pragma once

#include <vector>
#include <string>

std::vector<std::string> processQueries(
    const std::vector<std::vector<int>>& table,
    const std::vector<std::pair<int, int>>& queries
);