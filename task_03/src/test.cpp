
#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "task3.hpp"

TEST(PhoneCombinations, Example23) {
  std::string s = "23";
  auto res = runKeyboardTree(s);
  std::vector<std::string> expect = {"ad", "ae", "af", "bd", "be",
                                     "bf", "cd", "ce", "cf"};
  ASSERT_EQ(expect, res);
}

TEST(PhoneCombinations, SingleDigit) {
  std::string s = "2";
  auto res = runKeyboardTree(s);
  std::vector<std::string> expect = {"a", "b", "c"};
  ASSERT_EQ(expect, res);
}

TEST(PhoneCombinations, Example79) {
  std::string s = "79";
  auto res = runKeyboardTree(s);
  std::vector<std::string> expect = {"pw", "px", "py", "pz", "qw", "qx",
                                     "qy", "qz", "rw", "rx", "ry", "rz",
                                     "sw", "sx", "sy", "sz"};
  ASSERT_EQ(expect, res);
}

TEST(PhoneCombinations, EmptyInput) {
  std::string s = "";
  auto res = runKeyboardTree(s);
  std::vector<std::string> expect = {""};
  ASSERT_EQ(expect, res);
}

TEST(PhoneCombinations, LengthAndSorted) {
  std::string s = "234";
  auto res = runKeyboardTree(s);
  ASSERT_EQ(27u, res.size());
  for (auto &t : res) ASSERT_EQ((size_t)s.size(), t.size());
  ASSERT_TRUE(std::is_sorted(res.begin(), res.end()));
}

TEST(PhoneCombinations, OtherDigit) {
  std::string s = "8";
  auto res = runKeyboardTree(s);
  std::vector<std::string> expect = {"t", "u", "v"};
  ASSERT_EQ(expect, res);
}
