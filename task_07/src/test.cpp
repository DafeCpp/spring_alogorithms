#include <gtest/gtest.h>
#include "splay.hpp"
#include <vector>

TEST(SplayTreeTest, AllOperations) {
    // само дерево 9 5 11 3 7 6 8 (по уровням)
    Node<int, int> *A = new Node<int, int>(3, 52);
    Node<int, int> *B = new Node<int, int>(6, 6666);
    Node<int, int> *C = new Node<int, int>(8, 8852);
    Node<int, int> *D = new Node<int, int>(11, 1171);
    Node<int, int> *X = new Node<int, int>(7, 7732, B, C);
    Node<int, int> *P = new Node<int, int>(5, 555, A, X);
    Node<int, int> *G = new Node<int, int>(9, 999, P, D);
    SplayTree<int, int> Tr(G);

    // тесты на сплей
    Tr.Splay(P);
    std::vector<int> tree_after_1sp = Tr.tree_vector(P);
    std::vector<int> expect_list1 = {5, 3, 9, 7, 11, 6, 8};
    EXPECT_EQ(tree_after_1sp, expect_list1);

    Tr.Splay(X);
    std::vector<int> tree_after_2sp = Tr.tree_vector(P);
    std::vector<int> expect_list2 = {7, 5, 9, 3, 6, 8, 11};
    EXPECT_EQ(tree_after_2sp, expect_list2);

    // наше дерево выглядит так: 7 5 9 3 6 8 11
    /*
            7
           /  \
          5    9
         / \  / \
        3  6  8  11
    */

    // тестик на поиск(даём ключ, получаем значение)
    int val1 = Tr.Search(3);
    EXPECT_EQ(val1, 52);
    int val2 = Tr.Search(5);
    EXPECT_EQ(val2, 555);
    int val3 = Tr.Search(9);
    EXPECT_EQ(val3, 999);
    std::vector<int> expected_after_search_test = {9, 5, 11, 3, 7, 6, 8};
    std::vector<int> tree_after_search_test = Tr.tree_vector(Tr.getRoot());
    EXPECT_EQ(expected_after_search_test, tree_after_search_test);

    // наше дерево выглядит так: 9 5 11 3 7 6 8
    /*
            9
           / \
          5   11
         / \
        3   7
           / \
          6   8
    */

    // тестик на максимум
    int max = Tr.maximum()->key;
    EXPECT_EQ(max, 11);

    // тестик на удаление(одновременно и merge проверили)
    Tr.Remove(X);
    std::vector<int> expected_tree_after_remove = {6, 5, 9, 3, 8, 11};
    std::vector<int> tree_after_remove = Tr.tree_vector(Tr.getRoot());
    EXPECT_EQ(expected_tree_after_remove, tree_after_remove);

    // наше дерево выглядит так: 6 5 9 3 8 11
    /*
         6
        / \
       5   9
      /   / \
     3   8   11
    */

    // тестик на вставку
    Node<int, int> *I = new Node<int, int>(4, 45444);
    Tr.Insert(I);
    std::vector<int> expected_tree_after_insert = {4, 3, 6, 5, 9, 8, 11};
    std::vector<int> tree_after_insert = Tr.tree_vector(Tr.getRoot());
    EXPECT_EQ(expected_tree_after_insert, tree_after_insert);

    // наше дерево выглядит так: 4 3 6 5 9 8 11
    /*
        4
       / \
      3   6
         / \
        5   9
           / \
          8   11
    */
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}