#include <gtest/gtest.h>
#include <vector>
#include "FindSum.hpp"


TEST(TwoPointersTest, BasicCase) {
    std::vector<int> arr = {1, 2, 4};
    int target = 6;
    
    std::pair<int, int> expected = {2, 4};
    ASSERT_EQ(find_pair_with_sum(target, arr), expected);
}


TEST(TwoPointersTest, NoSolution) {
    std::vector<int> arr = {1, 2, 5};
    int target = 67;
    
    std::pair<int, int> expected = {-1, -1};
    ASSERT_EQ(find_pair_with_sum(target, arr), expected);
}


TEST(TwoPointersTest, NegativeNumbers) {
    std::vector<int> arr = {-5, -2, 0, 3, 8};
    int target = 3;
    
    std::pair<int, int> expected = {-5, 8};
    ASSERT_EQ(find_pair_with_sum(target, arr), expected);
}
