
#include <gtest/gtest.h>
#include "solution.hpp"

TEST(ButtonPhoneTest, OneLetter) {
    std::vector<std::string> expected1 = {"a", "b", "c"};
    std::vector<std::string> res1 = ButtonPhone("2");
    ASSERT_EQ(res1, expected1);

    std::vector<std::string> expected2 = {"w", "x", "y", "z"};
    std::vector<std::string> res2 = ButtonPhone("9");
    ASSERT_EQ(res2, expected2);
}

TEST(ButtonPhoneTest, TwoLetters) {
    std::vector<std::string> expected1 = {"pw", "px", "py", "pz", "qw", "qx", "qy", "qz", "rw", "rx", "ry", "rz", "sw", "sx", "sy", "sz"};
    std::vector<std::string> res1 = ButtonPhone("79");
    ASSERT_EQ(res1, expected1);

    std::vector<std::string> expected2 = {"gg", "gh", "gi", "hg", "hh", "hi", "ig", "ih", "ii"};
    std::vector<std::string> res2 = ButtonPhone("44");
    ASSERT_EQ(res2, expected2);
}

TEST(ButtonPhoneTest, ThreeLetters) {
    std::vector<std::string> expected1 = {"ajw", "ajx", "ajy", "ajz", "akw", "akx", "aky", "akz", "alw", "alx", "aly", "alz", "bjw", "bjx", "bjy", "bjz", "bkw", "bkx", "bky", "bkz", "blw", "blx", "bly", "blz", "cjw", "cjx", "cjy", "cjz", "ckw", "ckx", "cky", "ckz", "clw", "clx", "cly", "clz"};
    std::vector<std::string> res1 = ButtonPhone("259");
    ASSERT_EQ(res1, expected1);

    std::vector<std::string> expected2 = {"ddd", "dde", "ddf", "ded", "dee", "def", "dfd", "dfe", "dff", "edd", "ede", "edf", "eed", "eee", "eef", "efd", "efe", "eff", "fdd", "fde", "fdf", "fed", "fee", "fef", "ffd", "ffe", "fff"};
    std::vector<std::string> res2 = ButtonPhone("333");
    ASSERT_EQ(res2, expected2);
}

TEST(ButtonPhoneTest, FourLetters) {
    std::vector<std::string> expected = {"amwj", "amwk", "amwl", "amxj", "amxk", "amxl", "amyj", "amyk", "amyl", "amzj", "amzk", "amzl", "anwj", "anwk", "anwl", "anxj", "anxk", "anxl", "anyj", "anyk", "anyl", "anzj", "anzk", "anzl", "aowj", "aowk", "aowl", "aoxj", "aoxk", "aoxl", "aoyj", "aoyk", "aoyl", "aozj", "aozk", "aozl", "bmwj", "bmwk", "bmwl", "bmxj", "bmxk", "bmxl", "bmyj", "bmyk", "bmyl", "bmzj", "bmzk", "bmzl", "bnwj", "bnwk", "bnwl", "bnxj", "bnxk", "bnxl", "bnyj", "bnyk", "bnyl", "bnzj", "bnzk", "bnzl", "bowj", "bowk", "bowl", "boxj", "boxk", "boxl", "boyj", "boyk", "boyl", "bozj", "bozk", "bozl", "cmwj", "cmwk", "cmwl", "cmxj", "cmxk", "cmxl", "cmyj", "cmyk", "cmyl", "cmzj", "cmzk", "cmzl", "cnwj", "cnwk", "cnwl", "cnxj", "cnxk", "cnxl", "cnyj", "cnyk", "cnyl", "cnzj", "cnzk", "cnzl", "cowj", "cowk", "cowl", "coxj", "coxk", "coxl", "coyj", "coyk", "coyl", "cozj", "cozk", "cozl"};
    std::vector<std::string> res = ButtonPhone("2695");
    ASSERT_EQ(res, expected);
}