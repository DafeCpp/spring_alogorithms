
#include <gtest/gtest.h>
#include <sys/types.h>

#include <algorithm>
#include <random>
#include <vector>

#include "queue.hpp"
#include "solution.hpp"

TEST(MinQueue, Random) {
  MinQueue queue;

  std::random_device dev;
  std::mt19937 rng(dev());

  std::uniform_int_distribution<int> distr_gen(-1000, 1000);
  std::uniform_int_distribution<int> distr_action(0, 100);

  for (uint repetion = 0; repetion < 1000; ++repetion) {
    int should_remain = distr_action(rng) + 1;
    int should_pull = distr_action(rng);

    for (uint i = 0; i < should_remain + should_pull; ++i)
      queue.Push(distr_gen(rng));
    for (uint i = 0; i < should_pull; ++i) queue.Pull();

    int queue_min = queue.GetMin();
    int actual_min = queue.Pull();
    while (!queue.IsEmpty()) actual_min = std::min(actual_min, queue.Pull());

    ASSERT_EQ(queue_min, actual_min);
  }
}

TEST(FishPerDay, EdgeSimple) {
  std::vector<int> prices{1, 2, 3, 2, 3};
  std::vector<int> expected_res{5, 0, 0, 0, 0};

  auto actual_res = FishPerDay(prices, 99);

  ASSERT_EQ(expected_res.size(), actual_res.size());
  for (uint i = 0; i < expected_res.size(); ++i)
    ASSERT_EQ(actual_res[i], expected_res[i]) << "res differ at pos " << i;
}

TEST(FishPerDay, EdgeComplex) {
  std::vector<int> prices{2, 3, 1, 2, 3};
  std::vector<int> expected_res{2, 0, 3, 0, 0};

  auto actual_res = FishPerDay(prices, 99);

  ASSERT_EQ(expected_res.size(), actual_res.size());
  for (uint i = 0; i < expected_res.size(); ++i)
    ASSERT_EQ(actual_res[i], expected_res[i]) << "res differ at pos " << i;
}

TEST(FishPerDay, Complex) {
  int k = 3;
  std::vector<int> prices{1, 6, 5, 7, 9, 5, 3, 6, 5, 9, 11, 8, 2};
  std::vector<int> expected_res{3, 0, 2, 0, 0, 1, 3, 0, 2, 0, 0, 1, 1};

  auto actual_res = FishPerDay(prices, k);

  ASSERT_EQ(expected_res.size(), actual_res.size());
  for (uint i = 0; i < expected_res.size(); ++i)
    ASSERT_EQ(actual_res[i], expected_res[i]) << "res differ at pos " << i;
}
