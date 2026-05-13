#include <gtest/gtest.h>
#include "solution.hpp"

TEST(FindBorderTest, Simple) {
    std::vector<int> a = {0, 0, 0, 1, 1, 1, 1};
    ASSERT_EQ(FindBorder(a), 2);

    std::vector<int> b = {0, 1};
    ASSERT_EQ(FindBorder(b), 0);

    std::vector<int> c = {0, 0, 0, 0, 0, 0, 0, 1};
    ASSERT_EQ(FindBorder(c), 6);

    std::vector<int> d = {0, 1, 1, 1, 1};
    ASSERT_EQ(FindBorder(d), 0);
    
    std::vector<int> many = {0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1};
    int ans = FindBorder(many);
    bool check = ans < many.size() - 1 && !many[ans]  && many[ans + 1];
    ASSERT_EQ(check, true);
}
