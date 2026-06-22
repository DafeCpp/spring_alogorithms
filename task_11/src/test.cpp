
#include <gtest/gtest.h>

#include <string>

#include "FindAnagramIndex.h"

TEST(Func11, BasicExample) {
  std::string s = "abcsrlfcxdms";
  std::string p = "lrf";
  EXPECT_EQ(FindAnagramIndex(s, p), 5);
}

TEST(Func11, NotFound) {
  std::string s = "smnkfwlvk";
  std::string p = "nmsf";
  EXPECT_EQ(FindAnagramIndex(s, p), -1);
}

TEST(Func11, PermutationAtStart) {
  std::string s = "abcabc";
  std::string p = "cab";
  EXPECT_EQ(FindAnagramIndex(s, p), 1);
}

TEST(Func11, SingleChar) {
  std::string s = "a";
  std::string p = "a";
  EXPECT_EQ(FindAnagramIndex(s, p), 1);
}

TEST(Func11, EndOfString) {
  std::string s = "zzabc";
  std::string p = "abc";
  EXPECT_EQ(FindAnagramIndex(s, p), 3);
}
