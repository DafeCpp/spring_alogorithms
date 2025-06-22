#include <gtest/gtest.h>
#include <vector>

#include "find_numbers.hpp"

TEST(FindNumberOfamountTest, SimpleCase) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int summa = 8;
    std::vector<int> expected = {3, 5};
    ASSERT_EQ(FindNumberOfamount(vec, summa), expected);
}

TEST(FindNumberOfamountTest, FirstAndLastElements) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int summa = 6;
    std::vector<int> expected = {1, 5};
    ASSERT_EQ(FindNumberOfamount(vec, summa), expected);
}

TEST(FindNumberOfamountTest, NoPairFound) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int summa = 10;
    EXPECT_THROW(FindNumberOfamount(vec, summa), std::runtime_error);
}

TEST(FindNumberOfamountTest, EmptyVector) {
    std::vector<int> vec;
    int summa = 5;
    EXPECT_THROW(FindNumberOfamount(vec, summa), std::runtime_error);
}
