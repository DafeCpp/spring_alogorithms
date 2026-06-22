#pragma once

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Solve(int n, int m,
                               const std::vector<std::vector<int>>& table,
                               const std::vector<std::pair<int, int>>& queries);