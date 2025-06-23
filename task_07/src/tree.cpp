#include "tree.hpp"

#include <stdexcept>

// ----------------------------------- NODE ------------------------------------

SplayTree::SplayTreeNode::SplayTreeNode(int key, int value)
    : key(key), value(value) {}

void SplayTree::SplayTreeNode::Rot2(SplayTree::SplayTreeNode* root,
                                    SplayTree::SplayTreeNode* lower,
                                    SplayTree::SplayTreeNode* higher) {
  SplayTree::SplayTreeNode *A, *B, *C;
  if (lower->key < higher->key) {
    //        h
    //      l   C
    //     A B
    A = lower->L;
    B = lower->R;
    C = higher->R;
    //        l
    //      A   h
    //         B C
    lower->L = A;
    lower->R = higher;
    higher->L = B;
    higher->R = C;
  } else {
    //        h
    //      A   l
    //         B C
    A = higher->L;
    B = lower->L;
    C = lower->R;
    //        l
    //      h   C
    //     A B
    lower->L = higher;
    higher->L = A;
    higher->R = B;
    lower->R = C;
  }
  if (root) {
    if (root->key > lower->key)
      root->L = lower;
    else
      root->R = lower;
  }
}
void SplayTree::SplayTreeNode::Rot3(SplayTree::SplayTreeNode* root,
                                    SplayTree::SplayTreeNode* lower,
                                    SplayTree::SplayTreeNode* middle,
                                    SplayTree::SplayTreeNode* higher) {
  SplayTree::SplayTreeNode *A, *B, *C, *D;

  if (lower->key < middle->key && middle->key < higher->key) {
    /*
     *          h
     *        m' 'D
     *      l' 'C
     *     A"B
     */
    A = lower->L;
    B = lower->R;
    C = middle->R;
    D = higher->R;
    /*
     *       l
     *     A' 'm
     *       B' 'h
     *          C"D
     */
    lower->L = A;
    lower->R = middle;
    middle->L = B;
    middle->R = higher;
    higher->L = C;
    higher->R = D;
  } else if (higher->key < middle->key && middle->key < lower->key) {
    /*
     *       h
     *     A' 'm
     *       B' 'l
     *          C"D
     */
    A = higher->L;
    B = middle->L;
    C = lower->L;
    D = lower->R;
    /*
     *          l
     *        m' 'D
     *      h' 'C
     *     A"B
     */
    higher->L = A;
    higher->R = B;
    middle->L = higher;
    middle->R = C;
    lower->L = middle;
    lower->R = D;
  } else if (middle->key < lower->key && lower->key < higher->key) {
    /*
     *          h
     *        m' 'D
     *      A' 'l
     *         B"C
     */
    A = middle->L;
    B = lower->L;
    C = lower->R;
    D = higher->R;
    /*
     *          l
     *        m' 'h
     *       A"B C"D
     */
    lower->L = middle;
    lower->R = higher;
    middle->L = A;
    middle->R = B;
    higher->L = C;
    higher->R = D;
  } else if (higher->key < lower->key && lower->key < middle->key) {
    /*
     *         h
     *       A' 'm
     *         l' 'D
     *        B"C
     */
    A = higher->L;
    B = lower->L;
    C = lower->R;
    D = middle->R;
    /*
     *         l
     *       h' 'm
     *      A"B C"D
     */
    lower->L = higher;
    lower->R = middle;
    higher->L = A;
    higher->R = B;
    middle->L = C;
    middle->R = D;
  }

  if (root) {
    if (root->key > lower->key)
      root->L = lower;
    else
      root->R = lower;
  }
}

SplayTree::SplayTreeNode* SplayTree::SplayTreeNode::Splay(
    SplayTree::SplayTreeNode::PathType& path) {
  while (path.size() > 2) {
    SplayTree::SplayTreeNode* lower = path.back();
    path.pop_back();
    SplayTree::SplayTreeNode* middle = path.back();
    path.pop_back();
    SplayTree::SplayTreeNode* higher = path.back();
    path.pop_back();

    Rot3(path.empty() ? nullptr : path.back(), lower, middle, higher);

    path.push_back(lower);
  }
  if (path.size() == 2) {
    SplayTree::SplayTreeNode* lower = path.back();
    path.pop_back();
    SplayTree::SplayTreeNode* higher = path.back();
    path.pop_back();
    Rot2(nullptr, lower, higher);
    path.push_back(lower);
  }

  return path.back();
}

std::pair<int, int> SplayTree::SplayTreeNode::operator*() {
  return {key, value};
}

SplayTree::SplayTreeNode* SplayTree::SplayTreeNode::SearchExact(int key) {
  SplayTree::SplayTreeNode::PathType path;

  SplayTree::SplayTreeNode* node = this;
  while (node) {
    path.push_back(node);

    if (node->key < key)
      node = node->R;
    else if (node->key > key)
      node = node->L;
    else
      break;
  }
  if (node) {
    return Splay(path);
  }
  return nullptr;
}
SplayTree::SplayTreeNode* SplayTree::SplayTreeNode::SearchMinGTQ(int key) {
  SplayTree::SplayTreeNode::PathType path;

  SplayTree::SplayTreeNode* node = this;
  while (node) {
    path.push_back(node);

    if (node->key < key)
      node = node->R;
    else if (node->key > key)
      node = node->L;
    else
      break;
  }
  while (!path.empty() && path.back()->key < key) path.pop_back();

  if (path.empty()) return nullptr;

  return Splay(path);
}
SplayTree::SplayTreeNode* SplayTree::SplayTreeNode::SearchMaxLEQ(int key) {
  PathType path;

  SplayTree::SplayTreeNode* node = this;
  while (node) {
    path.push_back(node);

    if (node->key < key)
      node = node->R;
    else if (node->key > key)
      node = node->L;
    else
      break;
  }
  while (!path.empty() && path.back()->key > key) path.pop_back();

  if (path.empty()) return nullptr;

  return Splay(path);
}

SplayTree::SplayTreeNode* SplayTree::SplayTreeNode::SearchMax() {
  PathType path;
  auto node = this;
  while (node) {
    path.push_back(node);
    node = node->R;
  }

  return Splay(path);
}
SplayTree::SplayTreeNode* SplayTree::SplayTreeNode::SearchMin() {
  PathType path;
  auto node = this;
  while (node) {
    path.push_back(node);
    node = node->L;
  }

  return Splay(path);
}

std::pair<SplayTree::SplayTreeNode*, SplayTree::SplayTreeNode*>
SplayTree::SplayTreeNode::Split(int key) {
  SplayTree::SplayTreeNode* root = SearchMaxLEQ(key);
  if (root) {
    SplayTree::SplayTreeNode* R = root->R;
    root->R = nullptr;
    return {root, R};
  }
  root = SearchMinGTQ(key);
  if (root) {
    SplayTree::SplayTreeNode* L = root->L;
    root->L = nullptr;
    return {L, root};
  }
  throw std::runtime_error("WTF?");
}

SplayTree::SplayTreeNode* SplayTree::SplayTreeNode::Insert(
    SplayTree::SplayTreeNode* node) {
  auto [L, R] = this->Split(node->key);

  node->L = L;
  node->R = R;

  return node;
}
SplayTree::SplayTreeNode* SplayTree::SplayTreeNode::Insert(int key, int value) {
  return this->Insert(new SplayTree::SplayTreeNode(key, value));
}

SplayTree::SplayTreeNode* SplayTree::SplayTreeNode::MergeNonintersect(
    SplayTree::SplayTreeNode* A, SplayTree::SplayTreeNode* B) {
  A = A->SearchMax();
  if (A->key < B->key) {
    A->R = B;
    return A;
  }
  A = A->SearchMin();
  if (A->key > B->key) {
    A->L = B;
    return A;
  }
  throw std::runtime_error("impossible to merge intersection trees");
}

SplayTree::SplayTreeNode* SplayTree::SplayTreeNode::Delete(int key) {
  auto elem = this->SearchExact(key);

  if (!elem) throw std::runtime_error("cannot delete non-existing element");

  SplayTree::SplayTreeNode *L = elem->L, *R = elem->R;

  elem->L = nullptr;
  elem->R = nullptr;
  delete elem;

  if (L and R) return MergeNonintersect(L, R);
  if (L) return L;
  if (R) return R;
  return nullptr;
}

SplayTree::SplayTreeNode::~SplayTreeNode() {
  if (L) delete L;
  if (R) delete R;
}

// ----------------------------------- TREE ------------------------------------

SplayTree::SplayTree(SplayTreeNode* node) : root(node) {}
SplayTree::SplayTree(SplayTree&& old) : root(old.root) { old.root = nullptr; }

void SplayTree::Insert(int key, int value) {
  // Let's not check if the key already exists XD
  if (root)
    root = root->Insert(key, value);
  else
    root = new SplayTreeNode(key, value);
}
int SplayTree::SearchExact(int key) {
  if (!root) throw std::runtime_error("tree is empty");
  auto res = root->SearchExact(key);
  if (!res) {
    throw std::runtime_error("key not found");
  }
  root = res;
  return (*(*res)).second;
}
std::pair<int, int> SplayTree::SearchMinGTQ(int key) {
  if (!root) throw std::runtime_error("tree is empty");
  auto res = root->SearchMinGTQ(key);
  if (!res) {
    throw std::runtime_error("key not found");
  }
  root = res;
  return *(*res);
}
std::pair<int, int> SplayTree::SearchMaxLEQ(int key) {
  if (!root) throw std::runtime_error("tree is empty");
  auto res = root->SearchMaxLEQ(key);
  if (!res) {
    throw std::runtime_error("key not found");
  }
  root = res;
  return *(*res);
}
std::pair<int, int> SplayTree::SearchMin() {
  if (!root) throw std::runtime_error("tree is empty");
  auto res = root->SearchMin();
  if (!res) {
    throw std::runtime_error("key not found");
  }
  root = res;
  return *(*res);
}
std::pair<int, int> SplayTree::SearchMax() {
  if (!root) throw std::runtime_error("tree is empty");
  auto res = root->SearchMax();
  if (!res) {
    throw std::runtime_error("key not found");
  }
  root = res;
  return *(*res);
}
void SplayTree::Delete(int key) {
  if (!root) throw std::runtime_error("tree is empty");
  root = root->Delete(key);
}
std::pair<SplayTree, SplayTree> SplayTree::Split(int key) {
  if (!root) return {SplayTree(nullptr), SplayTree(nullptr)};
  auto [L, R] = root->Split(key);
  return {SplayTree(L), SplayTree(R)};
}
void SplayTree::Merge(SplayTree&& other) {
  if (!root) {
    root = other.root;
    return;
  }
  root = SplayTreeNode::MergeNonintersect(root, other.root);
}

SplayTree::~SplayTree() {
  if (root) delete root;
}
