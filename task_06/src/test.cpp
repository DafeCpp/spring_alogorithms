#include <gtest/gtest.h>
#include "fish.hpp"
#include <vector>
#include <climits>


TEST(FishBuyer, Example1) {
  std::vector<int> costs{5};
  ASSERT_EQ(5, minFishCost(costs, 1));
}

TEST(FishBuyer, Example2) {
  std::vector<int> costs{5,3,4};
  ASSERT_EQ(12, minFishCost(costs, 1));
}

TEST(FishBuyer, Example3) {
  std::vector<int> costs{5,3,4};
  ASSERT_EQ(11, minFishCost(costs, 3));
}


