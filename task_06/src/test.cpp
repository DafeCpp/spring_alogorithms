
#include <gtest/gtest.h>

#include "k_stat.hpp"
TEST(KSTAT, Simple) {
  std::vector<int> vec1{5, 2, 7, 1, 3, 9, 8, 4, 6, 10};
  std::vector<int> sorted_vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k = 5;
  int stat1 = FindKStat(vec1, k);
  int true_answer1 = sorted_vec1[k];
  ASSERT_EQ(stat1, true_answer1);
}

TEST(KSTAT, NegAndPos) {
  std::vector<int> vec2{-1, 1, 0, 5, 4, -3, 2, -4, -2, 3, -5};
  std::vector<int> sorted_vec2{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  int k = 5;
  int stat2 = FindKStat(vec2, k);
  int true_answer2 = sorted_vec2[k];
  ASSERT_EQ(stat2, true_answer2);
}

TEST(KSTAT, RepeatingNumbers) {
  std::vector<int> vec3{-1, 1, 0, 5, 4, -3, 2, -4, -2, 3, -5};
  std::vector<int> sorted_vec3{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  int k = 5;
  int stat3 = FindKStat(vec3, k);
  int true_answer3 = sorted_vec3[k];
  ASSERT_EQ(stat3, true_answer3);
}