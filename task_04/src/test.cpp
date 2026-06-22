
#include <gtest/gtest.h>

#include <stdexcept>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack stack;
  stack.Push(1);
  ASSERT_EQ(stack.Pop(), 1);
  stack.Push(1);
  stack.Push(2);
  ASSERT_EQ(stack.Pop(), 2);
  ASSERT_EQ(stack.Pop(), 1);
  stack.Push(1);
  stack.Push(2);
  ASSERT_EQ(stack.Pop(), 2);
  stack.Push(3);
  ASSERT_EQ(stack.Pop(), 3);
  ASSERT_EQ(stack.Pop(), 1);
}

TEST(StackTest, ThrowsOnEmptyPop) {
  Stack stack;
  EXPECT_THROW(stack.Pop(), std::out_of_range);
}

TEST(MinStackTest, Simple) {
  MinStack stack;
  stack.Push(1);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);
  stack.Push(1);
  stack.Push(2);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);
  ASSERT_EQ(stack.Pop(), 1);
  stack.Push(1);
  stack.Push(2);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);
  stack.Push(3);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 3);
  ASSERT_EQ(stack.Pop(), 1);
}

TEST(MinStackTest, HandlesRepeatedMinimums) {
  MinStack stack;
  stack.Push(3);
  stack.Push(1);
  stack.Push(1);
  stack.Push(2);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);
  ASSERT_EQ(stack.GetMin(), 3);
}

TEST(MinStackTest, ThrowsOnEmptyOperations) {
  MinStack stack;
  EXPECT_THROW(stack.Pop(), std::out_of_range);
  EXPECT_THROW(stack.GetMin(), std::out_of_range);
}
