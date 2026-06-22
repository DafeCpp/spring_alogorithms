#include <utility>



auto FindTwoSum(int expected, int size, int* nums)
{
    int left {0};
    int right {size-1};
    if (left == right || right == -1)
    {
        return std::make_pair(-1, -1);
    }
    while ((nums[left]+nums[right]) != expected) {
        if (nums[left]+nums[right] > expected)
        {
            right -= 1;
        }
        else 
        {
            left += 1;
        }
        if (left >= right)
        {
            return std::make_pair(-1, -1);
        }
    }
    return std::make_pair(nums[left], nums[right]);
};