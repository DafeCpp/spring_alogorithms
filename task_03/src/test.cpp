
#include <gtest/gtest.h>

#include <vector>

#include "topology_sort.hpp"

TEST(TopologyFuncTest, OrdinaryWeek) {
  std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
  ASSERT_EQ(TopologySort(temperatures), expected);
}

TEST(TopologyFuncTest, EmptyInput) {
  std::vector<int> temperatures = {};
  std::vector<int> expected = {};
  ASSERT_EQ(TopologySort(temperatures), expected);
}

TEST(TopologyFuncTest, SingleDay) {
  std::vector<int> temperatures = {30};
  std::vector<int> expected = {0};
  ASSERT_EQ(TopologySort(temperatures), expected);
}

TEST(TopologyFuncTest, IncreasingTemperatures) {
  std::vector<int> temperatures = {10, 20, 30, 40};
  std::vector<int> expected = {1, 1, 1, 0};
  ASSERT_EQ(TopologySort(temperatures), expected);
}

TEST(TopologyFuncTest, MixedTemperatures) {
  std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
  ASSERT_EQ(TopologySort(temperatures), expected);
}