
// #include <gtest/gtest.h>

// #include <stack>

// #include "stack.hpp"

// TEST(StackTest, Simple) {
//   Stack stack;
//   stack.Push(1);              // Stack [1]
//   ASSERT_EQ(stack.Pop(), 1);  // Stack []
//   stack.Push(1);              // Stack [1]
//   stack.Push(2);              // Stack [1, 2]
//   ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
//   ASSERT_EQ(stack.Pop(), 1);  // Stack []
//   stack.Push(1);              // Stack [1]
//   stack.Push(2);              // Stack [1, 2]
//   ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
//   stack.Push(3);              // Stack [1, 3]
//   ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
//   ASSERT_EQ(stack.Pop(), 1);  // Stack []
// }

// TEST(MinStackTest, Simple) {
//   MinStack stack;
//   stack.Push(1);  // Stack [1]
//   ASSERT_EQ(stack.GetMin(), 1);
//   ASSERT_EQ(stack.Pop(), 1);  // Stack []
//   stack.Push(1);              // Stack [1]
//   stack.Push(2);              // Stack [1, 2]
//   ASSERT_EQ(stack.GetMin(), 1);
//   ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
//   ASSERT_EQ(stack.Pop(), 1);  // Stack []
//   stack.Push(1);              // Stack [1]
//   stack.Push(2);              // Stack [1, 2]
//   ASSERT_EQ(stack.GetMin(), 1);
//   ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
//   stack.Push(3);              // Stack [1, 3]
//   ASSERT_EQ(stack.GetMin(), 1);
//   ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
//   ASSERT_EQ(stack.Pop(), 1);  // Stack []
// }