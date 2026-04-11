
#include <gtest/gtest.h>

#include <vector>

#include "topology_sort.hpp"

TEST(TopologySort, Simple) {
  vector<int> v1{1, 2, 3, 4, 5, 6};
  vector<int> v01{1, 1, 1, 1, 1, 0};
  vector<int> v2{67, 52, 42, 13, 2};
  vector<int> v02{0, 0, 0, 0, 0};
  vector<int> v3{52, 52, 52, 52, 52};
  vector<int> v4{23, 24, 25, 21, 29, 22, 26, 23};
  vector<int> v04{1, 1, 2, 1, 0, 1, 0, 0};
  vector<int> v5{-13, -5, 10, 10, 0, -3, -2, 4, -10};
  vector<int> v05{1, 1, 0, 0, 3, 1, 1, 0, 0};

  ASSERT_EQ(temperature_rise(v1), v01);  // по возрастанию
  ASSERT_EQ(temperature_rise(v2), v02);  // по убыванию
  ASSERT_EQ(temperature_rise(v3), v02);  // одинаковые числа
  ASSERT_EQ(temperature_rise(v4), v04);  // обычный
  ASSERT_EQ(temperature_rise(v5), v05);  // с отрицательными числами
}

TEST(TopologySort, Single) {
  vector<int> v{52};
  vector<int> v0{0};
  ASSERT_EQ(temperature_rise(v), v0);
}

TEST(TopologySort, Empty) {
  vector<int> v{};
  vector<int> v0{};
  ASSERT_EQ(temperature_rise(v), v0);
}
