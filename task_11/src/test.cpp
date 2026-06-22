#include <gtest/gtest.h>

#include <string>

#include "task11.hpp"

TEST(FindAnagramIndex, FoundAtStart) {
  std::string S = "cbaebabacd";
  std::string P = "abc";
  ASSERT_EQ(0, find_index(S, P));
}

TEST(FindAnagramIndex, FoundInMiddle) {
  std::string S = "befacbady";
  std::string P = "abc";
  ASSERT_EQ(3, find_index(S, P));
}

TEST(FindAnagramIndex, ExactMatch) {
  std::string S = "abcd";
  std::string P = "abcd";
  ASSERT_EQ(0, find_index(S, P));
}

TEST(FindAnagramIndex, PatternLongerThanString) {
  std::string S = "abc";
  std::string P = "abcdef";
  ASSERT_EQ(-1, find_index(S, P));
}

TEST(FindAnagramIndex, NoAnagramFound) {
  std::string S = "hello";
  std::string P = "world";
  ASSERT_EQ(-1, find_index(S, P));
}

TEST(FindAnagramIndex, DuplicateLetters) {
  std::string S = "afgzzaf";
  std::string P = "zaf";
  ASSERT_EQ(4, find_index(S, P));
}
