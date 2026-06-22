
#include <gtest/gtest.h>

#include <exception>
#include <stack>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack stack;
  stack.Push(1);              // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
}

TEST(MinStackTest, Simple) {
  MinStack stack;
  stack.Push(1);  // Stack [1]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
}

TEST(StackTest, EmptyAfterPushPop) {
  Stack stack;

  stack.Push(42);
  ASSERT_EQ(stack.Pop(), 42);

  ASSERT_TRUE(stack.Empty());
}

TEST(StackTest, NegativeValues) {
  Stack stack;

  stack.Push(-1);
  stack.Push(-5);

  ASSERT_EQ(stack.Pop(), -5);
  ASSERT_EQ(stack.Pop(), -1);
}

TEST(StackTest, ManyElements) {
  Stack stack;

  for (int i = 0; i < 100; ++i) {
    stack.Push(i);
  }

  for (int i = 99; i >= 0; --i) {
    ASSERT_EQ(stack.Pop(), i);
  }

  ASSERT_TRUE(stack.Empty());
}

TEST(StackTest, Top) {
  Stack stack;

  stack.Push(10);
  ASSERT_EQ(stack.Top(), 10);

  stack.Push(20);
  ASSERT_EQ(stack.Top(), 20);

  ASSERT_EQ(stack.Pop(), 20);
  ASSERT_EQ(stack.Top(), 10);
}

TEST(MinStackTest, SingleElement) {
  MinStack stack;

  stack.Push(5);

  ASSERT_EQ(stack.GetMin(), 5);
  ASSERT_EQ(stack.Pop(), 5);
}

TEST(MinStackTest, MinimumChanges) {
  MinStack stack;

  stack.Push(5);
  stack.Push(3);
  stack.Push(7);

  ASSERT_EQ(stack.GetMin(), 3);

  ASSERT_EQ(stack.Pop(), 7);
  ASSERT_EQ(stack.GetMin(), 3);

  ASSERT_EQ(stack.Pop(), 3);
  ASSERT_EQ(stack.GetMin(), 5);
}

TEST(MinStackTest, DuplicateMinimums) {
  MinStack stack;

  stack.Push(5);
  stack.Push(2);
  stack.Push(2);
  stack.Push(7);

  ASSERT_EQ(stack.GetMin(), 2);

  ASSERT_EQ(stack.Pop(), 7);
  ASSERT_EQ(stack.GetMin(), 2);

  ASSERT_EQ(stack.Pop(), 2);
  ASSERT_EQ(stack.GetMin(), 2);

  ASSERT_EQ(stack.Pop(), 2);
  ASSERT_EQ(stack.GetMin(), 5);
}

TEST(MinStackTest, NegativeValues) {
  MinStack stack;

  stack.Push(-1);
  stack.Push(-10);
  stack.Push(5);

  ASSERT_EQ(stack.GetMin(), -10);

  ASSERT_EQ(stack.Pop(), 5);
  ASSERT_EQ(stack.GetMin(), -10);

  ASSERT_EQ(stack.Pop(), -10);
  ASSERT_EQ(stack.GetMin(), -1);
}

TEST(MinStackTest, IncreasingSequence) {
  MinStack stack;

  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  stack.Push(4);

  ASSERT_EQ(stack.GetMin(), 1);

  ASSERT_EQ(stack.Pop(), 4);
  ASSERT_EQ(stack.Pop(), 3);
  ASSERT_EQ(stack.Pop(), 2);

  ASSERT_EQ(stack.GetMin(), 1);
}

TEST(MinStackTest, DecreasingSequence) {
  MinStack stack;

  stack.Push(4);
  stack.Push(3);
  stack.Push(2);
  stack.Push(1);

  ASSERT_EQ(stack.GetMin(), 1);

  ASSERT_EQ(stack.Pop(), 1);
  ASSERT_EQ(stack.GetMin(), 2);

  ASSERT_EQ(stack.Pop(), 2);
  ASSERT_EQ(stack.GetMin(), 3);

  ASSERT_EQ(stack.Pop(), 3);
  ASSERT_EQ(stack.GetMin(), 4);
}