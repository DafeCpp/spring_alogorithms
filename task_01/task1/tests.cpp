#include "two_sum.hpp"
#include <cassert>
#include <iostream>
#include <vector>

void runTests() {
    {
        std::vector<int> nums = {2, 7, 11, 15};
        std::vector<int> result = twoSum(nums, 9);
        assert((result == std::vector<int>{2, 7}));
    }
    {
        std::vector<int> nums = {1, 2, 3, 4};
        std::vector<int> result = twoSum(nums, 5);
        assert((result == std::vector<int>{1, 4}));
    }
    {
        std::vector<int> nums = {3, 3};
        std::vector<int> result = twoSum(nums, 6);
        assert((result == std::vector<int>{3, 3}));
    }
    {
        std::vector<int> nums = {1, 2, 3, 4};
        std::vector<int> result = twoSum(nums, 10);
        assert(result.empty());
    }
    {
        std::vector<int> nums;
        std::vector<int> result = twoSum(nums, 5);
        assert(result.empty());
    }
    {
        std::vector<int> nums = {5};
        std::vector<int> result = twoSum(nums, 5);
        assert(result.empty());
    }
    {
        std::vector<int> nums = {-4, -1, 0, 3, 5};
        std::vector<int> result = twoSum(nums, -1);
        assert((result == std::vector<int>{-4, 3}));
    }
    {
        std::vector<int> nums = {10, 20, 30};
        std::vector<int> result = twoSum(nums, 5);
        assert(result.empty());
    }
    {
        std::vector<int> nums = {1, 2, 3};
        std::vector<int> result = twoSum(nums, 10);
        assert(result.empty());
    }
    {
        std::vector<int> nums = {1, 2, 3, 4, 5};
        std::vector<int> result = twoSum(nums, 6);
        assert((result == std::vector<int>{1, 5}));
    }
    {
        std::vector<int> nums = {-5, -3, -2, 0, 1};
        std::vector<int> result = twoSum(nums, -5);
        assert((result == std::vector<int>{-5, 0}));
    }
}
int main() {
    runTests();
    return 0;
}