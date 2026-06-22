#include <gtest/gtest.h>
#include "phone.hpp"

TEST(Phone, Simple) {
    std::vector<std::string> expected = {"ad","ae","af","bd","be","bf","cd","ce","cf"};
    ASSERT_EQ(GetCombinations("23"), expected);
}

TEST(Phone, SingleDigit) {
        std::vector<std::string> expected6 = {"m","n","o"};
        std::vector<std::string> expected7 = {"p","q","r", "s"};
        ASSERT_EQ(GetCombinations("6"), expected6);
        ASSERT_EQ(GetCombinations("7"), expected7);
}

TEST(Phone, Empty) {
    std::vector<std::string> expected = {};
    ASSERT_EQ(GetCombinations(""), expected);
}