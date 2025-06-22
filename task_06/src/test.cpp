#include <gtest/gtest.h>
#include "task6.hpp"

#include <vector>

TEST(SearchNstatTest, SingleElement) {
    std::vector<int> vec = {5};
    EXPECT_EQ(SearchNstat(vec, 0), 5);
}

TEST(SearchNstatTest, AllSameElements) {
    std::vector<int> vec = {2, 2, 2, 2};
    EXPECT_EQ(SearchNstat(vec, 2), 2);
}

TEST(SearchNstatTest, SortedArray) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    EXPECT_EQ(SearchNstat(vec, 2), 3);
}

TEST(SearchNstatTest, ReverseSortedArray) {
    std::vector<int> vec = {5, 4, 3, 2, 1};
    EXPECT_EQ(SearchNstat(vec, 1), 2);
}

TEST(SearchNstatTest, RandomArray) {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6};
    EXPECT_EQ(SearchNstat(vec, 3), 3);
}

TEST(SearchNstatTest, PivotIsNth) {
    std::vector<int> vec = {3, 1, 4, 2, 5};
    EXPECT_EQ(SearchNstat(vec, 3), 4);
}

TEST(SearchNstatTest, AllGreaterThanPivot) {
    std::vector<int> vec = {6, 7, 8, 5};
    EXPECT_EQ(SearchNstat(vec, 3), 8);
}

TEST(SearchNstatTest, AllLessThanPivot) {
    std::vector<int> vec = {1, 2, 3, 5};
    EXPECT_EQ(SearchNstat(vec, 2), 3);
}