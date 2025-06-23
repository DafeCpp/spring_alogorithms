#pragma once

#include <utility>
#include <vector>

class SplayTree {
 private:
  class SplayTreeNode {
   private:
    int key;
    int value;
    SplayTreeNode* L = nullptr;
    SplayTreeNode* R = nullptr;

    typedef std::vector<SplayTreeNode*> PathType;

    static void Rot3(SplayTreeNode* root, SplayTreeNode* lower,
                     SplayTreeNode* middle, SplayTreeNode* higher);
    static void Rot2(SplayTreeNode* root, SplayTreeNode* lower,
                     SplayTreeNode* higher);
    static SplayTreeNode* Splay(PathType& path);

   public:
    SplayTreeNode() = default;
    SplayTreeNode(int key, int value);
    std::pair<int, int> operator*();
    SplayTreeNode* SearchExact(int key);
    SplayTreeNode* SearchMinGTQ(int key);
    SplayTreeNode* SearchMaxLEQ(int key);
    SplayTreeNode* SearchMin();
    SplayTreeNode* SearchMax();
    SplayTreeNode* Insert(SplayTreeNode* node);
    SplayTreeNode* Insert(int key, int value);
    SplayTreeNode* Delete(int key);
    static SplayTreeNode* MergeNonintersect(SplayTreeNode* A, SplayTreeNode* B);
    std::pair<SplayTreeNode*, SplayTreeNode*> Split(int key);

    ~SplayTreeNode();
  };

  SplayTreeNode* root = nullptr;
  SplayTree(SplayTreeNode*);

 public:
  SplayTree() = default;
  SplayTree(SplayTree const& other) = delete;
  SplayTree(SplayTree&& old);

  void Insert(int key, int value);
  int SearchExact(int key);
  std::pair<int, int> SearchMinGTQ(int key);
  std::pair<int, int> SearchMaxLEQ(int key);
  std::pair<int, int> SearchMin();
  std::pair<int, int> SearchMax();
  void Delete(int key);
  std::pair<SplayTree, SplayTree> Split(int key);
  void Merge(SplayTree&& other);

  ~SplayTree();
};
