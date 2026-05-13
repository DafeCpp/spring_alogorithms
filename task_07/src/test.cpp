#include <gtest/gtest.h>
#include "sort.hpp"
#include <ctime>
#include <random>
#include <algorithm>


TEST(Sort, Simple) {
    std::mt19937 mt(time(nullptr));

    int size = 10;
    std::vector<int> data1(size);
    for (int i = 0; i < size; ++i) {
        data1[i] = mt() % 30;
    }

    std::vector<int> sorted1(size);
    std::copy(data1.begin(), data1.end(), sorted1.begin());
    std::sort(sorted1.begin(), sorted1.end());
    SelectionSort(data1);
    ASSERT_EQ(data1, sorted1);

    size = 50;
    std::vector<int> data2(size);
    for (int i = 0; i < size; ++i) {
        data2[i] = mt() % 1000;
    }
    std::vector<int> sorted2(size);
    std::copy(data2.begin(), data2.end(), sorted2.begin());    
    std::sort(sorted2.begin(), sorted2.end());
    SelectionSort(data2);
    ASSERT_EQ(data2, sorted2);

    size = 500;
    std::vector<int> data3(size);
    for (int i = 0; i < size; ++i) {
      data3[i] = mt() % 100000;
    }
    std::vector<int> sorted3(size);
    std::copy(data3.begin(), data3.end(), sorted3.begin());
    std::sort(sorted3.begin(), sorted3.end());
    SelectionSort(data3);
    ASSERT_EQ(data3, sorted3);

    size = 1000;
    std::vector<int> data4(size);
    for (int i = 0; i < size; ++i) {
        data4[i] = mt() % 100000;
    }
    std::vector<int> sorted4(size);
    std::copy(data4.begin(), data4.end(), sorted4.begin());
    std::sort(sorted4.begin(), sorted4.end());
    SelectionSort(data4);
    ASSERT_EQ(data4, sorted4);
 }
