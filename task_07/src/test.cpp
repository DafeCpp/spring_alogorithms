#include <gtest/gtest.h>

#include <merge_sort.hpp>
#include <vector>

TEST(MergeSort, Simple) {
  std::vector<int> v1{1, 2, 3, 4, 5};
  std::vector<int> v2{5, 3, 1, 4, 2};
  std::vector<int> v3{5, 3, -7, 4, -2, 0};
  std::vector<int> v03{-7, -2, 0, 3, 4, 5};
  std::vector<int> v4{1, 1, 42, 0, 42, 42, 52, 42, 67, 52, -52, -52, -52};
  std::vector<int> v04{-52, -52, -52, 0, 1, 1, 42, 42, 42, 42, 52, 52, 67};
  std::vector<int> v5{15000, 20, 17, 13, 10, 8, 5, 2, -1, -52};
  std::vector<int> v05{-52, -1, 2, 5, 8, 10, 13, 17, 20, 15000};

  ASSERT_EQ(MergeSort(v1), v1);  // уже отсортированный
  ASSERT_EQ(MergeSort(v2), v1);  // нечетное количество элементов
  ASSERT_EQ(MergeSort(v3),
            v03);  // четное количество элементов + отрицательные числа
  ASSERT_EQ(MergeSort(v4), v04);  // c повторяющимися числами
  ASSERT_EQ(MergeSort(v5), v05);  // обратный
}

TEST(MergeSort, Empty) {
  std::vector<int> v_empty = {};
  ASSERT_EQ(MergeSort(v_empty), v_empty);
}

TEST(MergeSort, Single) {
  std::vector<int> v_single = {52};
  ASSERT_EQ(MergeSort(v_single), v_single);
}