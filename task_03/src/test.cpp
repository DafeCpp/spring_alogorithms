#include <gtest/gtest.h>

#include "phone_combinations.hpp"

TEST(PhoneCombinations, HandlesEmptyInput) {
  EXPECT_TRUE(BuildPhoneCombinations("").empty());
}

TEST(PhoneCombinations, BuildsSingleDigit) {
  EXPECT_EQ(BuildPhoneCombinations("2"),
            (std::vector<std::string>{"a", "b", "c"}));
}

TEST(PhoneCombinations, BuildsFourLetterDigit) {
  EXPECT_EQ(BuildPhoneCombinations("7"),
            (std::vector<std::string>{"p", "q", "r", "s"}));
}

TEST(PhoneCombinations, BuildsNineDigit) {
  EXPECT_EQ(BuildPhoneCombinations("9"),
            (std::vector<std::string>{"w", "x", "y", "z"}));
}

TEST(PhoneCombinations, BuildsLexicographicOrder) {
  EXPECT_EQ(BuildPhoneCombinations("23"),
            (std::vector<std::string>{"ad", "ae", "af", "bd", "be", "bf", "cd",
                                      "ce", "cf"}));
}

TEST(PhoneCombinations, BuildsTwoFourLetterDigits) {
  EXPECT_EQ(BuildPhoneCombinations("79"),
            (std::vector<std::string>{"pw", "px", "py", "pz", "qw", "qx", "qy",
                                      "qz", "rw", "rx", "ry", "rz", "sw", "sx",
                                      "sy", "sz"}));
}
