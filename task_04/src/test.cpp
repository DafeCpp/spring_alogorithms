
#include <gtest/gtest.h>

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