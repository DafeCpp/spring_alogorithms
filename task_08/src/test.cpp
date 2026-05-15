#include <gtest/gtest.h>

#include <vector>

#include "order_statistic.hpp"

TEST(Test, Simple) {
  std::vector<int> v1{0, 1};
  std::vector<int> v2{0, 0, 0, 1, 1};
  std::vector<int> v3{0, 0, 0, 0, 0, 1};
  std::vector<int> v4{0, 1, 1, 1, 1};
  std::vector<int> v5{0, 0, 1, 1, 1, 1};

  ASSERT_EQ(OrderStatistic(v1, 1, 0, v1.size() - 1), 0);
  ASSERT_EQ(OrderStatistic(v2, 1, 0, v2.size() - 1), 0);
  ASSERT_EQ(OrderStatistic(v3, 1, 0, v3.size() - 1), 0);
  ASSERT_EQ(OrderStatistic(v4, 1, 0, v4.size() - 1), 0);
  ASSERT_EQ(OrderStatistic(v5, 1, 0, v5.size() - 1), 0);

  ASSERT_EQ(OrderStatistic(v1, 2, 0, v1.size() - 1), 1);
  ASSERT_EQ(OrderStatistic(v2, 5, 0, v2.size() - 1), 1);
  ASSERT_EQ(OrderStatistic(v3, 6, 0, v3.size() - 1), 1);

  ASSERT_EQ(OrderStatistic(v2, 3, 0, v2.size() - 1), 0);
  ASSERT_EQ(OrderStatistic(v4, 3, 0, v4.size() - 1), 1);
  ASSERT_EQ(OrderStatistic(v5, 4, 0, v5.size() - 1), 1);
}

TEST(Test, DifferentNumbers) {
  // положительные числа
  std::vector<int> v1{7, 10, 4, 3, 20};
  ASSERT_EQ(OrderStatistic(v1, 1, 0, v1.size() - 1), 3);
  ASSERT_EQ(OrderStatistic(v1, 3, 0, v1.size() - 1), 7);
  ASSERT_EQ(OrderStatistic(v1, 5, 0, v1.size() - 1), 20);

  // отрицательные числа
  std::vector<int> v2{-5, -2, -8, -1, -3};
  ASSERT_EQ(OrderStatistic(v2, 1, 0, v2.size() - 1), -8);
  ASSERT_EQ(OrderStatistic(v2, 3, 0, v2.size() - 1), -3);
  ASSERT_EQ(OrderStatistic(v2, 5, 0, v2.size() - 1), -1);

  // положительные и отрицательные
  std::vector<int> v3{-10, 5, -3, 8, 0, -7, 2};
  ASSERT_EQ(OrderStatistic(v3, 1, 0, v3.size() - 1), -10);
  ASSERT_EQ(OrderStatistic(v3, 4, 0, v3.size() - 1), 0);
  ASSERT_EQ(OrderStatistic(v3, 7, 0, v3.size() - 1), 8);

  // повторяющиеся элементы
  std::vector<int> v4{5, 5, 5, 1, 1, 9, 9, 9, 9};
  ASSERT_EQ(OrderStatistic(v4, 1, 0, v4.size() - 1), 1);
  ASSERT_EQ(OrderStatistic(v4, 3, 0, v4.size() - 1), 5);
  ASSERT_EQ(OrderStatistic(v4, 6, 0, v4.size() - 1), 9);
  ASSERT_EQ(OrderStatistic(v4, 9, 0, v4.size() - 1), 9);
}

TEST(Test, TooSimple) {
  // один элемент
  std::vector<int> v1{42};
  ASSERT_EQ(OrderStatistic(v1, 1, 0, 0), 42);

  // два элемента
  std::vector<int> v2{100, 200};
  ASSERT_EQ(OrderStatistic(v2, 1, 0, 1), 100);
  ASSERT_EQ(OrderStatistic(v2, 2, 0, 1), 200);

  // два одинаковых элемента
  std::vector<int> v3{7, 7};
  ASSERT_EQ(OrderStatistic(v3, 1, 0, 1), 7);
  ASSERT_EQ(OrderStatistic(v3, 2, 0, 1), 7);

  // одинаковые
  std::vector<int> v4{3, 3, 3, 3, 3};
  for (int k = 1; k <= 5; k++) {
    ASSERT_EQ(OrderStatistic(v4, k, 0, v4.size() - 1), 3);
  }

  std::vector<int> v5{-1, 0, -1, 0, -2};
  ASSERT_EQ(OrderStatistic(v5, 1, 0, v5.size() - 1), -2);
  ASSERT_EQ(OrderStatistic(v5, 3, 0, v5.size() - 1), -1);
  ASSERT_EQ(OrderStatistic(v5, 5, 0, v5.size() - 1), 0);
}