#include <gtest/gtest.h>

#include <vector>

#include "get_combinations.hpp"

TEST(Test, Single) {
  // Одна цифра
  std::vector<std::string> empty{};
  std::vector<std::string> v2{"a", "b", "c"};
  std::vector<std::string> v3{"d", "e", "f"};
  std::vector<std::string> v4{"g", "h", "i"};
  std::vector<std::string> v5{"j", "k", "l"};
  std::vector<std::string> v6{"m", "n", "o"};
  std::vector<std::string> v7{"p", "q", "r", "s"};
  std::vector<std::string> v8{"t", "u", "v"};
  std::vector<std::string> v9{"w", "x", "y", "z"};

  ASSERT_EQ(GetCombinations("0"), empty);
  ASSERT_EQ(GetCombinations("1"), empty);
  ASSERT_EQ(GetCombinations("2"), v2);
  ASSERT_EQ(GetCombinations("3"), v3);
  ASSERT_EQ(GetCombinations("4"), v4);
  ASSERT_EQ(GetCombinations("5"), v5);
  ASSERT_EQ(GetCombinations("6"), v6);
  ASSERT_EQ(GetCombinations("7"), v7);
  ASSERT_EQ(GetCombinations("8"), v8);
  ASSERT_EQ(GetCombinations("9"), v9);
}

TEST(Test, TwoDigits) {
  // Две цифры
  std::vector<std::string> v1{"ad", "ae", "af", "bd", "be",
                              "bf", "cd", "ce", "cf"};
  std::vector<std::string> v2{"pw", "px", "py", "pz", "qw", "qx", "qy", "qz",
                              "rw", "rx", "ry", "rz", "sw", "sx", "sy", "sz"};
  ASSERT_EQ(GetCombinations("23"), v1);
  ASSERT_EQ(GetCombinations("79"), v2);
}

TEST(Test, ThreeDigits) {
  // Три цифры
  std::vector<std::string> v1{"adg", "adh", "adi", "aeg", "aeh", "aei", "afg",
                              "afh", "afi", "bdg", "bdh", "bdi", "beg", "beh",
                              "bei", "bfg", "bfh", "bfi", "cdg", "cdh", "cdi",
                              "ceg", "ceh", "cei", "cfg", "cfh", "cfi"};
  ASSERT_EQ(GetCombinations("234"), v1);
}

TEST(Test, Empty) {
  // Пустая строка
  std::vector<std::string> empty{};
  ASSERT_EQ(GetCombinations(""), empty);
}