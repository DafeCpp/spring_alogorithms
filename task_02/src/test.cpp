#include <gtest/gtest.h>
#include "finder.hpp"

TEST(FindBounder, Simple) {
  int nums1[5] = {0, 0, 0 ,1, 1};
  int nums2[4] = {0, 0, 1, 1};
  ASSERT_EQ(FindIdOfBounder(5, nums1), 2);
  ASSERT_EQ(FindIdOfBounder(4, nums2), 1);
}

TEST(FindBounder, BigArr){
  int arr[50];
  for (int i = 0; i < 40; ++i) arr[i] = 0;
  for (int i = 40; i < 50; ++i) arr[i] = 1;
  ASSERT_EQ(FindIdOfBounder(50, arr), 39);
}
