#include <gtest/gtest.h>

#include "task12.hpp"

using namespace std;

TEST(Task12Test, Simple1) { EXPECT_EQ(func(5, 2, {1, 3}), 3); }
TEST(Task12Test, Simple2) { EXPECT_EQ(func(11, 3, {1, 2, 5}), 3); }

TEST(Task12Test, ZeroAmount) { EXPECT_EQ(func(0, 3, {1, 2, 5}), 0); }

TEST(Task12Test, BedResult) { EXPECT_EQ(func(11, 1, {2}), -1); }

TEST(Task12Test, OnlyOneCoin) { EXPECT_EQ(func(23, 5, {1, 2, 5, 17, 23}), 1); }

TEST(Task12Test, GreedyTrap) { EXPECT_EQ(func(6, 3, {1, 3, 4}), 2); }