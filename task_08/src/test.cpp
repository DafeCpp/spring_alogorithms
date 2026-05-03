#include <gtest/gtest.h>
#include <vector>
#include "solution.hpp"

TEST(QuickSelect, Basic) {
    std::vector<int> arr = {7, 10, 4, 3, 20, 15};
    int n = arr.size();
    int k = 3;
    int result = quickSelect(arr, 0, n - 1, k - 1);
    ASSERT_EQ(result, 7);
}

TEST(QuickSelect, MinAndMax) {
    std::vector<int> arr = {12, 3, 5, 7, 4, 19, 26};
    int n = arr.size();
    std::vector<int> arr_copy = arr;
    ASSERT_EQ(quickSelect(arr_copy, 0, n - 1, 0), 3);


    arr_copy = arr;
    ASSERT_EQ(quickSelect(arr_copy, 0, n - 1, n - 1), 26);
}


TEST(QuickSelect, Duplicates) {
    std::vector<int> arr = {5, 2, 5, 1, 5, 3};
    int n = arr.size();
    ASSERT_EQ(quickSelect(arr, 0, n - 1, 3), 5);
}

TEST(QuickSelect, SingleElement) {
    std::vector<int> arr = {42};
    ASSERT_EQ(quickSelect(arr, 0, 0, 0), 42);
}

TEST(QuickSelect, SortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    ASSERT_EQ(quickSelect(arr, 0, n - 1, 2), 3);
}