#include <gtest/gtest.h>
#include <search.hpp>


TEST(Test, First_elem) {
  ASSERT_EQ(search({0,1,1,1,1}), 0);  // placeholder
}

TEST(Test, Easy) {
  ASSERT_EQ(search({0,0,1,1,1}), 1);  // placeholder
}
TEST(Test, Last_elem) {
  ASSERT_EQ(search({0,0,0,0,1}), 3);  // placeholder
}
TEST(Test, Hard) {
  ASSERT_EQ(search({0,0,0,0,0,0,0,0,0,0,1,1,1,1}), 9);  // placeholder
}
