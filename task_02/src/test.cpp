#include <gtest/gtest.h>

#include "stack.hpp"

TEST(StackTest, BasicOperations) {
  Stack<int> s;
  s.Push(1);
  s.Push(2);
  ASSERT_EQ(s.Top(), 2);
  s.Pop();
  ASSERT_EQ(s.Top(), 1);
  s.Pop();
  ASSERT_TRUE(s.IsEmpty());
}

TEST(StackTest, EmptyStack) {
  MinStack<int> s;
  EXPECT_TRUE(s.IsEmpty());
  EXPECT_THROW(s.Top(), std::runtime_error);
  EXPECT_THROW(s.Pop(), std::runtime_error);
}

TEST(MinStackTest, BasicOperations) {
  MinStack<int> s;
  s.Push(3);
  s.Push(5);
  ASSERT_EQ(s.FindMin(), 3);
  s.Push(2);
  ASSERT_EQ(s.FindMin(), 2);
  s.Pop();
  ASSERT_EQ(s.FindMin(), 3);
}

TEST(MinStackTest, DuplicateMins) {
  MinStack<int> s;
  s.Push(2);
  s.Push(2);
  ASSERT_EQ(s.FindMin(), 2);
  s.Pop();
  ASSERT_EQ(s.FindMin(), 2);
  s.Pop();
  EXPECT_THROW(s.FindMin(), std::runtime_error);
}

TEST(MinStackTest, ComplexSequence) {
  MinStack<int> s;
  s.Push(5);
  s.Push(3);
  s.Push(7);
  s.Push(1);
  s.Push(2);

  ASSERT_EQ(s.FindMin(), 1);
  s.Pop();
  ASSERT_EQ(s.FindMin(), 1);
  s.Pop();
  ASSERT_EQ(s.FindMin(), 3);
  s.Pop();
  ASSERT_EQ(s.FindMin(), 3);
  s.Pop();
  ASSERT_EQ(s.FindMin(), 5);
}