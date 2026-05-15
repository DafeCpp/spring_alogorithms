
#include <gtest/gtest.h>

#include <vector>

#include "temperature_rise.hpp"

TEST(Test, Simple) {
  std::vector<int> v1{1, 2, 3, 4, 5, 6};
  std::vector<int> v01{1, 1, 1, 1, 1, 0};
  std::vector<int> v2{67, 52, 42, 13, 2};
  std::vector<int> v02{0, 0, 0, 0, 0};
  std::vector<int> v3{52, 52, 52, 52, 52};
  std::vector<int> v4{23, 24, 25, 21, 29, 22, 26, 23};
  std::vector<int> v04{1, 1, 2, 1, 0, 1, 0, 0};
  std::vector<int> v5{-13, -5, 10, 10, 0, -3, -2, 4, -10};
  std::vector<int> v05{1, 1, 0, 0, 3, 1, 1, 0, 0};

  ASSERT_EQ(TemperatureRise(v1), v01);  // по возрастанию
  ASSERT_EQ(TemperatureRise(v2), v02);  // по убыванию
  ASSERT_EQ(TemperatureRise(v3), v02);  // одинаковые числа
  ASSERT_EQ(TemperatureRise(v4), v04);  // обычный
  ASSERT_EQ(TemperatureRise(v5), v05);  // с отрицательными числами
}

TEST(Test, Single) {
  std::vector<int> v{52};
  std::vector<int> v0{0};
  ASSERT_EQ(TemperatureRise(v), v0);
}

TEST(Test, Empty) {
  std::vector<int> v{};
  std::vector<int> v0{};
  ASSERT_EQ(TemperatureRise(v), v0);
}
