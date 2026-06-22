
#include <gtest/gtest.h>

#include "topology_sort.hpp"

#include <gtest/gtest.h>
#include <vector>
#include "topology_sort.hpp"


TEST(TopologySort, UsualDays) {
    std::vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
    
    EXPECT_EQ(topology_sort(temp.size(), temp), expected);
}

TEST(TopologySort, HigherEveryDay) {
    std::vector<int> temp = {10, 11, 12, 13};
    std::vector<int> expected = {1, 1, 1, 0}; 
    
    EXPECT_EQ(topology_sort(temp.size(), temp), expected);
}

TEST(TopologySort, LowerEveryDay) {
    std::vector<int> temp = {13, 12, 11, 10};
    std::vector<int> expected = {0, 0, 0, 0}; // Ни разу не потеплело
    
    EXPECT_EQ(topology_sort(temp.size(), temp), expected);
}

TEST(TopologySort, SameTemperatures) {
    std::vector<int> temp = {45, 45, 45, 45};
    std::vector<int> expected = {0, 0, 0, 0}; 
    
    EXPECT_EQ(topology_sort(temp.size(), temp), expected);
}

TEST(TopologySort, OneDay) {
    std::vector<int> temp = {10};
    std::vector<int> expected = {0};
    
    EXPECT_EQ(topology_sort(temp.size(), temp), expected);
}
