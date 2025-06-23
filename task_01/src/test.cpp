#include <gtest/gtest.h>

#include <algorithm>
#include <random>
#include <vector>

#include "solution.hpp"

TEST(BinarySearchSubtest, EdgeCases) {
  ASSERT_EQ(BinarySearchGEQ({1, 2, 3, 4, 5}, 1, 0, 4), 0);  // Stack []
  ASSERT_EQ(BinarySearchGEQ({1, 2, 3, 4, 5}, 5, 0, 4), 4);  // Stack []
}
TEST(BinarySearchSubtest, MiddleCases) {
  ASSERT_EQ(BinarySearchGEQ({0, 1, 2, 3, 4, 5}, 3, 0, 5), 3);  // Stack []
  ASSERT_EQ(BinarySearchGEQ({0, 1, 2, 3, 4, 5}, 4, 0, 5), 4);  // Stack []
}
TEST(BinarySearchSubtest, Inequality) {
  ASSERT_EQ(BinarySearchGEQ({0, 2, 4, 6, 8, 9}, 31, 0, 5), 5);  // Stack []
  ASSERT_EQ(BinarySearchGEQ({0, 2, 3, 6, 7, 9}, 5, 0, 5), 3);   // Stack []
  ASSERT_EQ(BinarySearchGEQ({1, 2, 3, 6, 7, 9}, 0, 0, 5), 0);   // Stack []
}
TEST(BinarySearchSubtest, Randomx100) {
  std::vector<int> arr(100);
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<int> dist_gen(0, 1000);
  std::uniform_int_distribution<int> dist_sample(0, arr.size() - 1);

  for (int repetion = 0; repetion < 10000; ++repetion) {
    for (int j = 0; j < arr.size(); ++j) arr[j] = dist_gen(rng);
    std::sort(arr.begin(), arr.end());

    int sample = dist_gen(rng);
    int res_pos = BinarySearchGEQ(arr, sample, 0, arr.size() - 1);

    if (res_pos != arr.size() - 1) ASSERT_GE(arr[res_pos], sample);
    if (res_pos > 0) ASSERT_LT(arr[res_pos - 1], sample);
  }
}

TEST(SolutionTest, Simple) {
  {
    auto [L, R] = FindPairMatchSum({1, 2, 3, 4, 8, 8, 8, 8, 9}, 13);
    ASSERT_EQ(L, 4);
    ASSERT_EQ(R, 9);
  }

  {
    auto [L, R] = FindPairMatchSum({1, 1, 1, 4, 8, 8, 8, 8, 9, 10, 11}, 13);
    ASSERT_EQ(L, 4);
    ASSERT_EQ(R, 9);
  }
}
TEST(SolutionTest, Random100of1000x1000) {
  std::vector<int> arr(100);

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<int> dist_gen(0, 1000);
  std::uniform_int_distribution<int> dist_sample(0, arr.size() - 1);

  for (int i = 0; i < 1000; ++i) {
    // gen
    for (int j = 0; j < 100; ++j) arr[j] = dist_gen(rng);
    // sort array according to task
    std::sort(arr.begin(), arr.end());

    // sample
    int first_sample = dist_sample(rng);
    int second_sample = first_sample;
    while (second_sample == first_sample) second_sample = dist_sample(rng);

    // target sum
    int sum = arr[first_sample] + arr[second_sample];

    // get answer
    auto [res_first, res_second] = FindPairMatchSum(arr, sum);

    // compare
    // ! we might get other indexes then A & B we sampled.
    // Let's test the sum and the existance of elements
    ASSERT_EQ(res_first + res_second, sum);

    auto search_iterator = arr.begin();
    while (search_iterator != arr.end() && *search_iterator != res_first)
      ++search_iterator;
    ASSERT_NE(search_iterator, arr.end());
    search_iterator = arr.begin();
    while (search_iterator != arr.end() && *search_iterator != res_second)
      ++search_iterator;
    ASSERT_NE(search_iterator, arr.end());
  }
}
