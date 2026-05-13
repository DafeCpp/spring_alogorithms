
#include <gtest/gtest.h>
#include "stack.hpp"
#include "min_stack.hpp"
#include <vector>

TEST(Stack, SimpleStack) {
    std::vector<int> arr = {4, 1, 3, 6, 7, 8};
    Stack stack;
    for (int i = 0; i < arr.size(); ++i) {
        stack.Push(arr[i]);
    }
    for (int i = arr.size() - 1; i >= 0; --i) {
        ASSERT_EQ(arr[i], stack.Pop());
    }
    stack.Push(1);
    stack.Push(2);
    ASSERT_EQ(stack.Pop(), 2);
    stack.Push(3);
    ASSERT_EQ(stack.Pop(), 3);
}

TEST(Stack, SimpleMinStack) {
    std::vector<int> arr = {8, 3, 4, 1, 5};
    MinStack stack;
    for (int i : arr) {
        stack.Push(i);
    }
    ASSERT_EQ(stack.GetMin(), 1);
    ASSERT_EQ(stack.Pop(), 5);
    ASSERT_EQ(stack.GetMin(), 1);
    ASSERT_EQ(stack.Pop(), 1);
    ASSERT_EQ(stack.GetMin(), 3);
}