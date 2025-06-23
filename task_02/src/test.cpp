
#include <gtest/gtest.h>

#include <algorithm>
#include <random>

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

TEST(MinStackTest, Random) {
  MinStack mstack;

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<int> dist(-1000000, 1000000);

  for (unsigned int repeation = 0; repeation < 1000; ++repeation) {
    constexpr unsigned int N = 1000;
    std::array<int, N> min;

    min[0] = dist(rng);
    mstack.Push(min[0]);
    ASSERT_EQ(min[0], mstack.GetMin());  // forward pass - zero
    for (unsigned int i = 1; i < N; ++i) {
      int value = dist(rng);

      min[i] = std::min(min[i - 1], value);
      mstack.Push(value);

      ASSERT_EQ(min[i], mstack.GetMin());  // forward pass
    }
    for (int i = N - 1; i >= 0; --i) {
      ASSERT_EQ(mstack.GetMin(), min[i]);  // backward pass

      mstack.Pop();
    }
  }
}
