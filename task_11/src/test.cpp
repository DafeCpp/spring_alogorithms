#include <gtest/gtest.h>

#include "solution.hpp"
TEST(FindSubstringTest, BasicExampleMatch) {
  std::string s = "abcsrlfcxdms";
  std::string p = "lrf";
  ASSERT_EQ(5, FindSubstring(s, p));
}
TEST(FindSubstringTest, Nothing) {
  std::string s = "smnkfwlvk";
  std::string p = "nmsf";
  ASSERT_EQ(-1, FindSubstring(s, p));
}
TEST(FindSubstringTest, Start) {
  std::string s = "abcabc";
  std::string p = "cab";

  ASSERT_EQ(1, FindSubstring(s, p));
}
TEST(FindSubstringTest, EdgeCases) {
  ASSERT_EQ(-1, FindSubstring("abc", "abcd"));
}