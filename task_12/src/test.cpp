#include <gtest/gtest.h>

#include "exchange_of_coins.hpp"

TEST(Test, Simple) {
  ASSERT_EQ(MinNumberOfCoins(15, {1, 5, 10}), 2);  // 10+5
  ASSERT_EQ(MinNumberOfCoins(0, {1, 2, 3}), 0);    // нулевая сумма
  ASSERT_EQ(MinNumberOfCoins(7, {2, 4, 6}), -1);   // нет
  ASSERT_EQ(MinNumberOfCoins(30, {10, 20, 30}), 1);     // 30
  ASSERT_EQ(MinNumberOfCoins(12, {1, 3, 5}), 4);        // 5+5+1+1
  ASSERT_EQ(MinNumberOfCoins(100, {25, 10, 5, 1}), 4);  // 25+25+25+25
  ASSERT_EQ(MinNumberOfCoins(999999, {1}), 999999);
}

TEST(Test, SingleCoin) {
  // Одна монета
  ASSERT_EQ(MinNumberOfCoins(5, {5}), 1);   // 5
  ASSERT_EQ(MinNumberOfCoins(10, {5}), 2);  // 5+5
  ASSERT_EQ(MinNumberOfCoins(3, {5}), -1);  // нет
}

TEST(Test, NegativesAndZero) {
  // С отрицательными номиналами и нулём
  std::vector<int> v = {-42, -52, 10, 10, 0, -3, -2, 4, -10};
  ASSERT_EQ(MinNumberOfCoins(20, v), 2);  // 10+10
  ASSERT_EQ(MinNumberOfCoins(4, v), 1);   // 4
  ASSERT_EQ(MinNumberOfCoins(3, v), -1);  // нет
}

TEST(Test, Empty) {
  // Пустой вектор номиналов
  std::vector<int> empty;
  ASSERT_EQ(MinNumberOfCoins(52, empty), -1);
  ASSERT_EQ(MinNumberOfCoins(0, empty), 0);
}

TEST(Test, AllSame) {
  // Все номиналы одинаковые
  std::vector<int> v = {52, 52, 52, 52, 52};
  ASSERT_EQ(MinNumberOfCoins(104, v), 2);  // 52+52
  ASSERT_EQ(MinNumberOfCoins(53, v), -1);  // нет
  ASSERT_EQ(MinNumberOfCoins(0, v), 0);
}

TEST(Test, EdgeCases) {
  // Граничные случаи
  ASSERT_EQ(MinNumberOfCoins(1, {2, 3, 5}),
            -1);  // минимальная монета больше суммы
  ASSERT_EQ(MinNumberOfCoins(1000000, {999983}), -1);
  ASSERT_EQ(MinNumberOfCoins(1, {1}), 1);
}
