
#include <gtest/gtest.h>

#include <bit>
#include <format>
#include <vector>

#include "sorting.hpp"

TEST(QSort, Binary16) {
  std::vector<int> arr(16);
  for (uint i = 0; i < (1 << 16); ++i) {
    for (uint j = 0; j < 16; ++j) arr[j] = (i >> j) & 1;

    sortings::qsort_inplace(arr);

    int target_res = (1 << std::popcount(i)) - 1;
    int actual_res = 0;

    for (uint j = 0; j < 16; ++j) actual_res = (actual_res << 1) | arr[j];

    ASSERT_EQ(std::format("{:016b}", target_res),
              std::format("{:016b}", actual_res))
        << std::format("sorting failed on binary pattern {} {:016b}", i, i);
  }
}

TEST(HeapSort, Binary16) {
  std::vector<int> arr(16);
  for (uint i = 0; i < (1 << 16); ++i) {
    for (uint j = 0; j < 16; ++j) arr[j] = (i >> (15 - j)) & 1;

    sortings::heapsort_inplace(arr);

    int target_res = (1 << std::popcount(i)) - 1;
    int actual_res = 0;

    for (uint j = 0; j < 16; ++j) actual_res = (actual_res << 1) | arr[j];

    ASSERT_EQ(std::format("{:016b}", target_res),
              std::format("{:016b}", actual_res))
        << std::format("sorting failed on binary pattern {} {:016b}", i, i);
  }
}
