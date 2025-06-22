#include "solution.hpp"
#include <vector>

int main() {
    {
        std::vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
        std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
        if (dailyTemperatures(input) != expected) return 1;
    }
    {
        std::vector<int> input = {5, 4, 3, 2, 1};
        std::vector<int> expected = {0, 0, 0, 0, 0};
        if (dailyTemperatures(input) != expected) return 2;
    }
    {
        std::vector<int> input = {42};
        std::vector<int> expected = {0};
        if (dailyTemperatures(input) != expected) return 3;
    }
    {
        std::vector<int> input = {30, 60, 90};
        std::vector<int> expected = {1, 1, 0};
        if (dailyTemperatures(input) != expected) return 4;
    }
    {
        std::vector<int> input = {50, 40, 30, 40, 50, 60, 30};
        std::vector<int> expected = {4, 2, 1, 1, 1, 0, 0};
        if (dailyTemperatures(input) != expected) return 5;
    }

    return 0;
}