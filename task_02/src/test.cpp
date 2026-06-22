#include <gtest/gtest.h>
#include "findindex.hpp"

TEST(FindIndex, SimpleTest) {
  std::vector<int> vec = {0, 1};
  int result = FindIndex(2, vec);
  ASSERT_EQ(result, 0);
}

TEST(FindIndex, ThreeElements) {
  std::vector<int> vec = {0, 0, 1};
  int result = FindIndex(3, vec);
  ASSERT_EQ(result, 1);
}

TEST(FindIndex, FourElements) {
  std::vector<int> vec = {0, 0, 0, 1};
  int result = FindIndex(4, vec);
  ASSERT_EQ(result, 2);
}

TEST(FindIndex, FiveElements) {
  std::vector<int> vec = {0, 0, 0, 0, 1};
  int result = FindIndex(5, vec);
  ASSERT_EQ(result, 3);
}

TEST(FindIndex, SixElements) {
  std::vector<int> vec = {0, 0, 0, 0, 0, 1};
  int result = FindIndex(6, vec);
  ASSERT_EQ(result, 4);
}

TEST(FindIndex, SevenElements) {
  std::vector<int> vec = {0, 0, 0, 0, 0, 0, 1};
  int result = FindIndex(7, vec);
  ASSERT_EQ(result, 5);
}

TEST(FindIndex, EightElements) {
  std::vector<int> vec = {0, 0, 0, 0, 0, 0, 0, 1};
  int result = FindIndex(8, vec);
  ASSERT_EQ(result, 6);
}

TEST(FindIndex, NineElements) {
  std::vector<int> vec = {0, 0, 0, 0, 0, 0, 0, 0, 1};
  int result = FindIndex(9, vec);
  ASSERT_EQ(result, 7);
}

TEST(FindIndex, TenElements) {
  std::vector<int> vec = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  int result = FindIndex(10, vec);
  ASSERT_EQ(result, 8);
}

TEST(FindIndex, ElevenElements) {
  std::vector<int> vec = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  int result = FindIndex(11, vec);
  ASSERT_EQ(result, 9);
}