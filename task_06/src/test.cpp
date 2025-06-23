
#include <gtest/gtest.h>

#include <algorithm>
#include <random>
#include <vector>

#include "k-stat.hpp"

TEST(KOrdinalStatistics, Simple16) {
  std::vector<int> arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (uint i = 0; i < 10; ++i)
    ASSERT_EQ(KOrdinalStatistics(arr, i), i);  // Stack []
}
TEST(KOrdinalStatistics, Simple23) {
  std::vector<int> arr{0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11,
                       12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
  for (uint i = 0; i < 23; ++i)
    ASSERT_EQ(KOrdinalStatistics(arr, i), i);  // Stack []
}

TEST(KOrdinalStatistics, SimpleShuffled) {
  const int N = 100;

  std::random_device dev;
  std::mt19937 rng(dev());

  std::vector<int> arr(N);
  for (uint i = 0; i < N; ++i) arr[i] = i;

  std::shuffle(arr.begin(), arr.end(), rng);

  for (uint i = 0; i < N; ++i)
    ASSERT_EQ(KOrdinalStatistics(arr, i), i);  // Stack []
}
