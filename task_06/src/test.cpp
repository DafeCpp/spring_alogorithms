#include <gtest/gtest.h>

#include <vector>

#include "task6.hpp"

using namespace std;

TEST(TopologySort, Simple) { ASSERT_EQ(1, 1); }

TEST(Task6Test, Example1) {
  vector<int> prices = {5};
  EXPECT_EQ(func(1, 1, prices), 5);
}

TEST(Task6Test, All_same_price) {
  vector<int> prices = {4, 4, 4, 4, 4};
  EXPECT_EQ(func(5, 3, prices), 20);
}

TEST(Task6Test, cheap_start) {
  vector<int> prices = {2, 8, 1, 5};
  EXPECT_EQ(func(4, 3, prices), 6);
}

TEST(Task6Test, full_storage) {
  vector<int> prices = {5, 3, 4};
  EXPECT_EQ(func(3, 3, prices), 11);
}

TEST(Task6Test, no_storage) {
  vector<int> prices = {5, 3, 4};
  EXPECT_EQ(func(3, 1, prices), 12);
}

TEST(Task6Test, single_day) {
  vector<int> prices = {5};
  EXPECT_EQ(func(1, 1, prices), 5);
}

TEST(Task6Test, siding_window) {
  vector<int> prices = {3, 1, 5, 2, 4};
  EXPECT_EQ(func(5, 2, prices), 9);
}