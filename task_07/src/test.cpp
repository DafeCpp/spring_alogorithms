#include <gtest/gtest.h>

#include <vector>

#include "tree.h"

TEST(AVL_TREE, InsertAndInOrder) {
  AVLTree<int> tree;
  tree.Insert(5);
  tree.Insert(2);
  tree.Insert(7);
  tree.Insert(1);
  tree.Insert(3);

  std::vector<int> expected{1, 2, 3, 5, 7};
  ASSERT_EQ(tree.InOrder(), expected);
}

TEST(AVL_TREE, Contains) {
  AVLTree<int> tree;
  tree.Insert(10);
  tree.Insert(20);
  tree.Insert(30);

  ASSERT_TRUE(tree.Contains(10));
  ASSERT_TRUE(tree.Contains(20));
  ASSERT_TRUE(tree.Contains(30));
  ASSERT_FALSE(tree.Contains(15));
  ASSERT_FALSE(tree.Contains(0));
}

TEST(AVL_TREE, RemoveLeaf) {
  AVLTree<int> tree;
  tree.Insert(50);
  tree.Insert(30);
  tree.Insert(70);
  tree.Insert(20);
  tree.Insert(40);

  tree.Remove(20);
  std::vector<int> expected{30, 40, 50, 70};
  ASSERT_EQ(tree.InOrder(), expected);
}

TEST(AVL_TREE, RemoveNodeWithOneChild) {
  AVLTree<int> tree;
  tree.Insert(50);
  tree.Insert(30);
  tree.Insert(70);
  tree.Insert(40);

  tree.Remove(30);
  std::vector<int> expected{40, 50, 70};
  ASSERT_EQ(tree.InOrder(), expected);
}

TEST(AVL_TREE, RemoveNodeWithTwoChildren) {
  AVLTree<int> tree;
  tree.Insert(50);
  tree.Insert(30);
  tree.Insert(70);
  tree.Insert(20);
  tree.Insert(40);
  tree.Insert(60);
  tree.Insert(80);

  tree.Remove(50);
  std::vector<int> expected{20, 30, 40, 60, 70, 80};
  ASSERT_EQ(tree.InOrder(), expected);
}

TEST(AVL_TREE, BalanceAfterInsert) {
  AVLTree<int> tree;
  tree.Insert(10);
  tree.Insert(20);
  tree.Insert(30);  // Должно вызвать левый поворот

  std::vector<int> expected{10, 20, 30};
  ASSERT_EQ(tree.InOrder(), expected);
}

TEST(AVL_TREE, BalanceAfterRemove) {
  AVLTree<int> tree;
  tree.Insert(50);
  tree.Insert(30);
  tree.Insert(70);
  tree.Insert(20);
  tree.Insert(40);
  tree.Insert(60);
  tree.Insert(80);

  tree.Remove(20);  // Может вызвать балансировку
  tree.Remove(40);  // Может вызвать балансировку

  std::vector<int> expected{30, 50, 60, 70, 80};
  ASSERT_EQ(tree.InOrder(), expected);
}

TEST(AVL_TREE, EmptyTree) {
  AVLTree<int> tree;
  ASSERT_FALSE(tree.Contains(10));
  ASSERT_TRUE(tree.InOrder().empty());

  tree.Remove(10);  // Не должно упасть
  ASSERT_TRUE(tree.InOrder().empty());
}

TEST(AVL_TREE, RepeatedElements) {
  AVLTree<int> tree;
  tree.Insert(5);
  tree.Insert(5);
  tree.Insert(2);
  tree.Insert(2);
  tree.Insert(7);

  std::vector<int> expected{2, 2, 5, 5, 7};
  ASSERT_EQ(tree.InOrder(), expected);
}

TEST(AVL_TREE, ComplexTest) {
  AVLTree<int> tree;
  tree.Insert(50);
  tree.Insert(30);
  tree.Insert(70);
  tree.Insert(20);
  tree.Insert(40);
  tree.Insert(60);
  tree.Insert(80);
  tree.Insert(15);
  tree.Insert(25);
  tree.Insert(35);
  tree.Insert(45);
  tree.Insert(55);
  tree.Insert(65);
  tree.Insert(75);
  tree.Insert(85);

  // Проверка содержимого
  ASSERT_TRUE(tree.Contains(50));
  ASSERT_TRUE(tree.Contains(25));
  ASSERT_FALSE(tree.Contains(100));

  // Удаление нескольких элементов
  tree.Remove(50);
  tree.Remove(20);
  tree.Remove(80);

  std::vector<int> expected{15, 25, 30, 35, 40, 45, 55, 60, 65, 70, 75, 85};
  ASSERT_EQ(tree.InOrder(), expected);
}