#include <gtest/gtest.h>
#include "task2.hpp"
#include <vector>


TEST(Test, Simple) {
std::vector<int> vec = {0, 0, 0, 1, 1, 1};
int res = FindPair(vec);
  ASSERT_EQ(2, res); 
}
TEST(Test, Empty){
std::vector<int> vec = {};
int res = FindPair(vec);
  ASSERT_EQ(0, res); 
}

TEST(Test, Small) {
std::vector<int> vec = {0,1};
int res = FindPair(vec);
  ASSERT_EQ(0, res); 
}

TEST(Test, Negative) {
std::vector<int> vec = {0, 0, -2, 1};
int res = FindPair(vec);
  ASSERT_EQ(2, res); 
}

