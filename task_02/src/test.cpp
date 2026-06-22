#include <gtest/gtest.h>
#include <vector>
#include "FindIndex.hpp"


TEST(FindIndexTest, MinimalArray) {
    std::vector<int> v = {0, 1};
    ASSERT_EQ(FindIndex(v), 0);
}


TEST(FindIndexTest, MidTransition) {
    std::vector<int> v = {0, 0, 0, 1, 1, 1};
    ASSERT_EQ(FindIndex(v), 2);
}


TEST(FindIndexTest, ImmediateTransition) {
    std::vector<int> v = {0, 1, 1, 1, 1};
    ASSERT_EQ(FindIndex(v), 0);
}