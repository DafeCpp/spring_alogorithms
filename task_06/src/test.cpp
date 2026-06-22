
#include <gtest/gtest.h>

#include <climits>
#include <vector>

#include "task6.h"

TEST(FishBuyer, Example1) {
  std::vector<int> costs{5};
  ASSERT_EQ(5LL, totalfishcost(1, 1, costs));
}

TEST(FishBuyer, Example2) {
  std::vector<int> costs{5, 3, 4};
  ASSERT_EQ(12LL, totalfishcost(3, 1, costs));
}

TEST(FishBuyer, Example3) {
  std::vector<int> costs{5, 3, 4};
  ASSERT_EQ(11LL, totalfishcost(3, 3, costs));
}

TEST(FishBuyer, KOneEqualsSum) {
  std::vector<int> costs{7, 1, 5, 3};
  long long expected = 0;
  for (int x : costs) expected += x;
  ASSERT_EQ(expected, totalfishcost((int)costs.size(), 1, costs));
}

TEST(FishBuyer, LargeValues) {
  std::vector<int> costs(50, 1000);
  int N = (int)costs.size();
  ASSERT_EQ((long long)N * 1000LL, totalfishcost(N, 10, costs));
}