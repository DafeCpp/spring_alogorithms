
#include <gtest/gtest.h>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack<int> stack;
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
  MinStack<int> stack;
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

TEST(Stack, Custom) {
  Stack<int> stack;
  stack.Push(10);
  ASSERT_EQ(10, stack.Pop());

  EXPECT_THROW(stack.Pop(), std::out_of_range);
}

TEST(MinStack, Custom) {
  MinStack<int> stack;
  stack.Push(10);
  stack.Push(2);
  stack.Push(17);
  ASSERT_EQ(2, stack.GetMin());

  stack.Pop();
  stack.Pop();
  stack.Pop();
  EXPECT_THROW(stack.Pop(), std::out_of_range);

  stack.Push(10);
  stack.Push(10);
  stack.Push(10);
  ASSERT_EQ(10, stack.GetMin());
}