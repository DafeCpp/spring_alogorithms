#include <gtest/gtest.h>
#include "task9.hpp"
#include <vector>

TEST(TableSortTest, AllColumnsAscending) {
    std::vector<std::vector<int>> table = {
        {1, 10, 100},
        {2, 20, 200},
        {3, 30, 300},
        {4, 40, 400}
    };
    
    auto reach = PreprocessMaxReach(table);
    
    EXPECT_TRUE(CheckRangeSorted(reach, 0, 3));  // Весь диапазон
    EXPECT_TRUE(CheckRangeSorted(reach, 1, 2));  // Часть диапазона
    EXPECT_TRUE(CheckRangeSorted(reach, 0, 0));  // Одна строка
}
