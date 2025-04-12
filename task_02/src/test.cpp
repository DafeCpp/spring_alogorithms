
#include <gtest/gtest.h>


#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack<int> stack;
  stack.push_element(1);              // Stack [1]
  ASSERT_EQ(stack.pop_element(), 1);  // Stack []
  stack.push_element(1);              // Stack [1]
  stack.push_element(2);              // Stack [1, 2]
  ASSERT_EQ(stack.pop_element(), 2);  // Stack [1]
  ASSERT_EQ(stack.pop_element(), 1);  // Stack []
  stack.push_element(1);              // Stack [1]
  stack.push_element(2);              // Stack [1, 2]
  ASSERT_EQ(stack.pop_element(), 2);  // Stack [1]
  stack.push_element(3);              // Stack [1, 3]
  ASSERT_EQ(stack.pop_element(), 3);  // Stack [1]
  ASSERT_EQ(stack.pop_element(), 1);  // Stack []
}

TEST(MinStackTest, Simple) {
  MinStack<int> stack;
  stack.push_element(1);  // Stack [1]
  ASSERT_EQ(stack.get_min(), 1);
  ASSERT_EQ(stack.pop_element(), 1);  // Stack []
  stack.push_element(1);              // Stack [1]
  stack.push_element(2);              // Stack [1, 2]
  ASSERT_EQ(stack.get_min(), 1);
  ASSERT_EQ(stack.pop_element(), 2);  // Stack [1]
  ASSERT_EQ(stack.pop_element(), 1);  // Stack []
  stack.push_element(1);              // Stack [1]
  stack.push_element(2);              // Stack [1, 2]
  ASSERT_EQ(stack.get_min(), 1);
  ASSERT_EQ(stack.pop_element(), 2);  // Stack [1]
  stack.push_element(3);              // Stack [1, 3]
  ASSERT_EQ(stack.get_min(), 1);
  ASSERT_EQ(stack.pop_element(), 3);  // Stack [1]
  ASSERT_EQ(stack.pop_element(), 1);  // Stack []
}