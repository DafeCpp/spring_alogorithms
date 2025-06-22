#include "two_sum.hpp"

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    int left_index = 0;
    int right_index = nums.size() - 1;
    
    while (left_index < right_index) {
        const int sum = nums[left_index] + nums[right_index];
        
        if (sum == target) {
            return {nums[left_index], nums[right_index]};
        }
        else if (sum < target) {
            left_index++;
        }
        else {
            right_index--;
        }
    }
    
    return {};
}