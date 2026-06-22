#include <gtest/gtest.h>

#include <vector>

#include "get_combinations.hpp"

TEST(Test, Single) {
  // Одна цифра
  std::vector<std::string> empty{};
  std::vector<std::string> expected2{"a", "b", "c"};
  std::vector<std::string> expected3{"d", "e", "f"};
  std::vector<std::string> expected4{"g", "h", "i"};
  std::vector<std::string> expected5{"j", "k", "l"};
  std::vector<std::string> expected6{"m", "n", "o"};
  std::vector<std::string> expected7{"p", "q", "r", "s"};
  std::vector<std::string> expected8{"t", "u", "v"};
  std::vector<std::string> expected9{"w", "x", "y", "z"};

  ASSERT_EQ(GetCombinations("0"), empty);
  ASSERT_EQ(GetCombinations("1"), empty);
  ASSERT_EQ(GetCombinations("2"), expected2);
  ASSERT_EQ(GetCombinations("3"), expected3);
  ASSERT_EQ(GetCombinations("4"), expected4);
  ASSERT_EQ(GetCombinations("5"), expected5);
  ASSERT_EQ(GetCombinations("6"), expected6);
  ASSERT_EQ(GetCombinations("7"), expected7);
  ASSERT_EQ(GetCombinations("8"), expected8);
  ASSERT_EQ(GetCombinations("9"), expected9);
}

TEST(Test, TwoDigits) {
  // Две цифры
  std::vector<std::string> expected1{"ad", "ae", "af", "bd", "be",
                                     "bf", "cd", "ce", "cf"};
  std::vector<std::string> expected2{"pw", "px", "py", "pz", "qw", "qx",
                                     "qy", "qz", "rw", "rx", "ry", "rz",
                                     "sw", "sx", "sy", "sz"};
  ASSERT_EQ(GetCombinations("23"), expected1);
  ASSERT_EQ(GetCombinations("79"), expected2);
}

TEST(Test, ThreeDigits) {
  // Три цифры
  std::vector<std::string> expected{
      "adg", "adh", "adi", "aeg", "aeh", "aei", "afg", "afh", "afi",
      "bdg", "bdh", "bdi", "beg", "beh", "bei", "bfg", "bfh", "bfi",
      "cdg", "cdh", "cdi", "ceg", "ceh", "cei", "cfg", "cfh", "cfi"};
  ASSERT_EQ(GetCombinations("234"), expected);
}

TEST(Test, Empty) {
  // Пустая строка
  std::vector<std::string> empty{};
  ASSERT_EQ(GetCombinations(""), empty);
}