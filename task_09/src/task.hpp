#include <utility>
#include <vector>

std::vector<bool> IsThereSortedColumns(
    const std::vector<std::vector<int>>& matrix,
    const std::vector<std::pair<size_t, size_t>>& l_and_r);

std::vector<std::vector<int>> BuildPrefixes(
    const std::vector<std::vector<int>>& matrix);