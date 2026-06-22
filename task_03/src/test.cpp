#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "task3.hpp"

TEST(PhoneTest, SingleDigit2) {
  std::vector<std::string> result = letterCombinations("2");
  std::vector<std::string> expected = {"a", "b", "c"};
  EXPECT_EQ(result, expected);
}

TEST(PhoneTest, SingleDigit7) {
  std::vector<std::string> result = letterCombinations("7");
  std::vector<std::string> expected = {"p", "q", "r", "s"};
  EXPECT_EQ(result, expected);
}

TEST(PhoneTest, TwoDigits23) {
  std::vector<std::string> result = letterCombinations("23");
  std::vector<std::string> expected = {"ad", "ae", "af", "bd", "be",
                                       "bf", "cd", "ce", "cf"};
  EXPECT_EQ(result, expected);
}

TEST(PhoneTest, TwoDigits79) {
  std::vector<std::string> result = letterCombinations("79");
  std::vector<std::string> expected = {"pw", "px", "py", "pz", "qw", "qx",
                                       "qy", "qz", "rw", "rx", "ry", "rz",
                                       "sw", "sx", "sy", "sz"};
  EXPECT_EQ(result, expected);
}

TEST(PhoneTest, ThreeDigits234) {
  std::vector<std::string> result = letterCombinations("234");
  EXPECT_EQ(result.size(), 27);
}