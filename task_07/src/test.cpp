#include <gtest/gtest.h>
#include "sort.hpp"

TEST(Sort, Simple) {
    std::vector<int> arr1 = {5, 3, 1, 4, 2};
    QuickSort(arr1.size(), arr1);
    std::vector<int> expected1 = {1, 2, 3, 4, 5};
    ASSERT_EQ(arr1, expected1);
    std::vector<int> arr2 = {-3, 5, 0, -1, 10, -7, 3};
    QuickSort(arr2.size(), arr2);
    std::vector<int> expected2 = {-7, -3, -1, 0, 3, 5, 10};
    ASSERT_EQ(arr2, expected2);
}

TEST(Sort, Empty) {
        std::vector<int> empty = {};
        QuickSort(empty.size(), empty);
        std::vector<int> expected1 = {};
        ASSERT_EQ(empty, expected1);
        std::vector<int> arr = {42};
        QuickSort(arr.size(), arr);
        std::vector<int> expected2 = {42};
        ASSERT_EQ(arr, expected2);
}

TEST(Sort, Repetition) {
    std::vector<int> arr = {3, 3, 1, 1, 2, 2};
    QuickSort(arr.size(), arr);
    std::vector<int> expected = {1, 1, 2, 2, 3, 3};
    ASSERT_EQ(arr, expected);
}

TEST(Sort, Reverse) {
    std::vector<int> arr = {10, 9, 8, 7, 6, 5};
    QuickSort(arr.size(), arr);
    std::vector<int> expected = {5, 6, 7, 8, 9, 10};
    ASSERT_EQ(arr, expected);
}

TEST(Sort, Sorted) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    QuickSort(arr.size(), arr);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    ASSERT_EQ(arr, expected);
}