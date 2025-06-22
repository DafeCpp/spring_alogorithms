
#include <gtest/gtest.h>

#include <stack>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack<int> stack;
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
  MinStack<int> stack;
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

// ------------------------- Stack ----------------------------

TEST(StackTest, BasicPushPop) {
  Stack<int> s;
  s.Push(1);
  s.Push(2);
  EXPECT_EQ(s.Pop(), 2);
  EXPECT_EQ(s.Pop(), 1);
}

TEST(StackTest, IsEmptyInitially) {
  Stack<int> s;
  EXPECT_TRUE(s.IsEmpty());
  EXPECT_EQ(s.Size(), 0);
}

TEST(StackTest, SizeIncreasesAndDecreases) {
  Stack<int> s;
  s.Push(1);
  s.Push(2);
  EXPECT_EQ(s.Size(), 2);
  s.Pop();
  EXPECT_EQ(s.Size(), 1);
}

TEST(StackTest, PopFromEmptyStackThrows) {
  Stack<int> s;
  EXPECT_THROW(s.Pop(), std::runtime_error);
}

// ------------------------- MinStack ----------------------------

TEST(MinStackTest, GetMinBasic) {
  MinStack<int> s;
  s.Push(5);
  s.Push(3);
  s.Push(7);
  EXPECT_EQ(s.GetMin(), 3);
  s.Pop();  // pop 7
  EXPECT_EQ(s.GetMin(), 3);
  s.Pop();  // pop 3
  EXPECT_EQ(s.GetMin(), 5);
}

TEST(MinStackTest, IsEmptyInitially) {
  MinStack<int> s;
  EXPECT_TRUE(s.IsEmpty());
  EXPECT_EQ(s.Size(), 0);
}

TEST(MinStackTest, SizeWorksCorrectly) {
  MinStack<int> s;
  s.Push(10);
  s.Push(20);
  EXPECT_EQ(s.Size(), 2);
  s.Pop();
  EXPECT_EQ(s.Size(), 1);
}

TEST(MinStackTest, PopFromEmptyStackThrows) {
  MinStack<int> s;
  EXPECT_THROW(s.Pop(), std::runtime_error);
}

TEST(MinStackTest, GetMinFromEmptyThrows) {
  MinStack<int> s;
  EXPECT_THROW(s.GetMin(), std::runtime_error);
}

// ------------------------- MaxStack ----------------------------

TEST(MaxStackTest, GetMaxBasic) {
  MaxStack<int> s;
  s.Push(1);
  s.Push(3);
  s.Push(2);
  EXPECT_EQ(s.GetMax(), 3);
  s.Pop();  // pop 2
  EXPECT_EQ(s.GetMax(), 3);
  s.Pop();  // pop 3
  EXPECT_EQ(s.GetMax(), 1);
}

TEST(MaxStackTest, IsEmptyInitially) {
  MaxStack<int> s;
  EXPECT_TRUE(s.IsEmpty());
}

TEST(MaxStackTest, PopFromEmptyThrows) {
  MaxStack<int> s;
  EXPECT_THROW(s.Pop(), std::runtime_error);
}

TEST(MaxStackTest, GetMaxFromEmptyThrows) {
  MaxStack<int> s;
  EXPECT_THROW(s.GetMax(), std::runtime_error);
}

TEST(MaxStackTest, SizeWorksCorrectly) {
  MaxStack<int> s;
  EXPECT_EQ(s.Size(), 0);
  s.Push(42);
  EXPECT_EQ(s.Size(), 1);
  s.Pop();
  EXPECT_EQ(s.Size(), 0);
}