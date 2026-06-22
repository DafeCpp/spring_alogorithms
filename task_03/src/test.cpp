#include <gtest/gtest.h>

#include <algorithm>
#include <set>

#include "phone_algorithm.hpp"

TEST(PhoneKeyboardBasic, SingleDigit2) {
  std::vector<std::string> expected = {"a", "b", "c"};
  ASSERT_EQ(PhoneAlgorithm("2"), expected);
}

TEST(PhoneKeyboardBasic, SingleDigit9) {
  std::vector<std::string> expected = {"w", "x", "y", "z"};
  ASSERT_EQ(PhoneAlgorithm("9"), expected);
}

TEST(PhoneKeyboardBasic, Digits23) {
  std::vector<std::string> expected = {"ad", "ae", "af", "bd", "be",
                                       "bf", "cd", "ce", "cf"};
  ASSERT_EQ(PhoneAlgorithm("23"), expected);
}

TEST(PhoneKeyboardBasic, Digits79) {
  std::vector<std::string> expected = {"pw", "px", "py", "pz", "qw", "qx",
                                       "qy", "qz", "rw", "rx", "ry", "rz",
                                       "sw", "sx", "sy", "sz"};
  ASSERT_EQ(PhoneAlgorithm("79"), expected);
}

TEST(PhoneKeyboardBasic, Digits22) {
  std::vector<std::string> expected = {"aa", "ab", "ac", "ba", "bb",
                                       "bc", "ca", "cb", "cc"};
  ASSERT_EQ(PhoneAlgorithm("22"), expected);
}

TEST(PhoneKeyboardBasic, Digits34) {
  std::vector<std::string> expected = {"dg", "dh", "di", "eg", "eh",
                                       "ei", "fg", "fh", "fi"};
  ASSERT_EQ(PhoneAlgorithm("34"), expected);
}

TEST(PhoneKeyboardBasic, Digits222Count) {
  ASSERT_EQ(PhoneAlgorithm("222").size(), 27);
}

TEST(PhoneKeyboardBasic, Digits777Count) {
  ASSERT_EQ(PhoneAlgorithm("777").size(), 64);
}

TEST(PhoneKeyboardBasic, Digits234Count) {
  ASSERT_EQ(PhoneAlgorithm("234").size(), 27);
}

TEST(PhoneKeyboardBasic, LexicographicalOrder23) {
  auto result = PhoneAlgorithm("23");

  ASSERT_EQ(result.front(), "ad");
  ASSERT_EQ(result.back(), "cf");
}

TEST(PhoneKeyboardCorner, EmptyString) {
  std::vector<std::string> expected;
  ASSERT_EQ(PhoneAlgorithm(""), expected);
}

TEST(PhoneKeyboardCorner, LongOnlyThreeLetters) {
  ASSERT_EQ(PhoneAlgorithm("22222").size(), 243);
}

TEST(PhoneKeyboardCorner, LongOnlyFourLetters) {
  ASSERT_EQ(PhoneAlgorithm("9999").size(), 256);
}

TEST(PhoneKeyboardCorner, ResultLengthMatchesInput) {
  auto result = PhoneAlgorithm("279");

  for (const auto& s : result) {
    ASSERT_EQ(s.size(), 3);
  }
}

TEST(PhoneKeyboardCorner, NoDuplicates) {
  auto result = PhoneAlgorithm("79");

  std::set<std::string> uniq(result.begin(), result.end());

  ASSERT_EQ(result.size(), uniq.size());
}

TEST(PhoneKeyboardCorner, FirstAndLastFor79) {
  auto result = PhoneAlgorithm("79");

  ASSERT_EQ(result.front(), "pw");
  ASSERT_EQ(result.back(), "sz");
}

TEST(PhoneKeyboardCorner, CountFor79) {
  ASSERT_EQ(PhoneAlgorithm("79").size(), 16);
}

TEST(PhoneKeyboardCorner, CountFor2345) {
  ASSERT_EQ(PhoneAlgorithm("2345").size(), 81);
}

TEST(PhoneKeyboardCorner, CountFor279) {
  ASSERT_EQ(PhoneAlgorithm("279").size(), 48);
}

TEST(PhoneKeyboardCorner, SortedOrder) {
  auto result = PhoneAlgorithm("23");

  ASSERT_TRUE(std::is_sorted(result.begin(), result.end()));
}