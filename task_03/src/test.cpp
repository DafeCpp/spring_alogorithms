#include <gtest/gtest.h>

#include <vector>

#include "get_combinations.hpp"

using namespace std;

TEST(TopologySort, Simple) { ASSERT_EQ(1, 1); }

TEST(TopologySort, Single) {
  ASSERT_EQ(get_combinations("2"), 1);
  ASSERT_EQ(get_combinations("1"), "");
}
