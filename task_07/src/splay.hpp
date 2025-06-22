#ifndef SP_TREE_HPP
#define SP_TREE_HPP

#include <iostream>
#include <memory>
#include <queue>
#include <stdexcept>
#include <vector>

template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node<K, V> *left_child{nullptr};
  Node<K, V> *right_child{nullptr};
  Node<K, V> *parent{nullptr};

  Node(const K &key_, const V &value_, Node<K, V> *left = nullptr,
       Node<K, V> *right = nullptr, Node *parent = nullptr)
      : key(key_),
        value(value_),
        left_child(left),
        right_child(right),
        parent(parent) {
    if (left_child) {
      left_child->parent = this;
    }
    if (right_child) {
      right_child->parent = this;
    }
  }

  ~Node() {
    delete left_child;
    delete right_child;
  }

  bool operator==(const Node &other) const {
    return (left_child == other.left_child) &&
           (right_child == other.right_child) && (parent == other.parent) &&
           (key == other.key);
  }
};

template <typename K, typename V>
class SplayTree {
 public:
  std::vector<K> tree_vector(Node<K, V> *x);
  Node<K, V> *getRoot() const { return root; }
  void PrintTree();

  void Splay(Node<K, V> *node);

  V Search(K key_);
  Node<K, V> *maximum();
  bool Contains(const K &key);
  bool IsEmpty() { return root == nullptr; }

  void Insert(Node<K, V> *another);
  void Remove(Node<K, V> *x);

  void Merge(SplayTree<K, V> *another_tree);

  SplayTree() : root(nullptr) {}
  SplayTree(Node<K, V> *root_) : root(root_) {}
  ~SplayTree() { delete root; }

 private:
  Node<K, V> *root;

  void zig(Node<K, V> *x);
  void left_zig(Node<K, V> *x);
  void right_zig(Node<K, V> *x);

  void zig_zig(Node<K, V> *x);
  void zig_zag(Node<K, V> *x);
};

template <typename K, typename V>
void SplayTree<K, V>::right_zig(Node<K, V> *x) {
  if (x->parent == nullptr) {
    throw std::runtime_error("Нет родителя, zig невозможен");
  }
  Node<K, V> *parent = x->parent;
  Node<K, V> *parent_of_parent = parent->parent;

  parent->left_child = x->right_child;
  if (parent->left_child != nullptr) {
    parent->left_child->parent = parent;
  }
  parent->parent = (x);
  x->right_child = parent;
  x->parent = parent_of_parent;
  if (parent_of_parent != nullptr) {
    if (parent_of_parent->left_child == parent) {
      parent_of_parent->left_child = x;
    } else {
      parent_of_parent->right_child = x;
    }
  }
  if (parent_of_parent == nullptr) {
    root = x;
  }
}

template <typename K, typename V>
void SplayTree<K, V>::left_zig(Node<K, V> *x) {
  if (x->parent == nullptr) {
    throw std::runtime_error("Нет родителя, zig невозможен");
  }
  Node<K, V> *parent = x->parent;
  Node<K, V> *parent_of_parent = parent->parent;

  parent->right_child = x->left_child;
  if (parent->right_child != nullptr) {
    parent->right_child->parent = parent;
  }
  parent->parent = x;
  x->left_child = parent;
  x->parent = parent_of_parent;
  if (parent_of_parent != nullptr) {
    if (parent_of_parent->left_child == parent) {
      parent_of_parent->left_child = x;
    } else {
      parent_of_parent->right_child = x;
    }
  }
  if (parent_of_parent == nullptr) {
    root = x;
  }
}

template <typename K, typename V>
void SplayTree<K, V>::zig(Node<K, V> *x) {
  if (x->parent->left_child == x) {
    right_zig(x);
  } else {
    left_zig(x);
  }
}

template <typename K, typename V>
void SplayTree<K, V>::zig_zig(Node<K, V> *x) {
  Node<K, V> *parent = x->parent;
  Node<K, V> *parent_of_parent = parent->parent;
  if (x == nullptr || x->parent == nullptr || x->parent->parent == nullptr) {
    return;  // Нельзя выполнить zig_zig, если нет родителя или дедушки
  }
  zig(x);
  zig(x);
}

template <typename K, typename V>
void SplayTree<K, V>::zig_zag(Node<K, V> *x) {
  Node<K, V> *parent = x->parent;
  Node<K, V> *parent_of_parent = parent->parent;
  if (x == nullptr || x->parent == nullptr || x->parent->parent == nullptr) {
    return;  // Нельзя выполнить zig_zag, если нет родителя или дедушки
  }
  zig(x);
  zig(x);
}

template <typename K, typename V>
void SplayTree<K, V>::Splay(Node<K, V> *x) {
  while (x->parent != nullptr) {
    Node<K, V> *parent = x->parent;
    Node<K, V> *parent_of_parent = parent->parent;
    if (parent_of_parent == nullptr) {
      zig(x);
      return;
    }
    if ((parent_of_parent->left_child == parent && parent->left_child == x) ||
        (parent_of_parent->right_child == parent && parent->right_child == x)) {
      zig_zig(x);
    }
    if ((parent_of_parent->left_child == parent && parent->right_child == x) ||
        (parent_of_parent->right_child == parent && parent->left_child == x)) {
      zig_zag(x);
    }
  }
}

template <typename K, typename V>
V SplayTree<K, V>::Search(K key_) {
  Node<K, V> *x = root;
  while (x != nullptr) {
    if (x->key == key_) {
      Splay(x);
      return x->value;
    }
    if (key_ < x->key) {
      x = x->left_child;
    } else {
      x = x->right_child;
    }
  }
  throw std::runtime_error("This object wasn't found");
}

template <typename K, typename V>
bool SplayTree<K, V>::Contains(const K &key) {
  try {
    Search(key);
  } catch (const std::runtime_error &error) {
    return false;
  }
  return true;
}

template <typename K, typename V>
Node<K, V> *SplayTree<K, V>::maximum() {
  Node<K, V> *max = root;
  while (max->right_child != nullptr) {
    max = max->right_child;
  }
  return max;
}

template <typename K, typename V>
void SplayTree<K, V>::Insert(Node<K, V> *another) {
  if (root == nullptr) {
    root = another;
    return;
  }
  Node<K, V> *t = root;
  Node<K, V> *parent = nullptr;
  while (t != nullptr) {
    parent = t;
    if (another->key < t->key) {
      t = t->left_child;
    } else {
      t = t->right_child;
    }
  }
  another->parent = parent;
  if (another->key < parent->key) {
    parent->left_child = another;
  } else {
    parent->right_child = another;
  }

  Splay(another);
}

template <typename K, typename V>
void SplayTree<K, V>::Merge(SplayTree<K, V> *another_tree) {
  /*Для слияния деревьев T1 и T2, в которых все ключи T1 меньше ключей в T2,
  делаем Splay для максимального элемента T1,
  тогда у корня T1 не будет правого ребенка.
  После этого делаем T2 правым ребенком T1.*/
  if (another_tree == nullptr) {
    return;
  }
  if (root == nullptr) {
    root = another_tree->root;
    if (root != nullptr) {
      root->parent = nullptr;
    }
    another_tree->root = nullptr;
    delete another_tree;
    return;
  }
  Node<K, V> *max = maximum();
  Splay(max);
  Node<K, V> *another_root = another_tree->getRoot();
  if (another_root != nullptr) {
    max->right_child = another_root;
    another_root->parent = max;
  }
  another_tree->root = nullptr;
  delete another_tree;
}

template <typename K, typename V>
void SplayTree<K, V>::Remove(Node<K, V> *x) {
  if (x == nullptr || !Contains(x->key)) {
    return;
  }
  Splay(x);
  SplayTree<K, V> *another_tree = new SplayTree<K, V>(x->right_child);
  root = x->left_child;
  if (another_tree->getRoot()->parent != nullptr) {
    another_tree->getRoot()->parent = nullptr;
  }
  if (root != nullptr) {
    root->parent = nullptr;
  }
  Merge(another_tree);
}

template <typename K, typename V>
std::vector<K> SplayTree<K, V>::tree_vector(Node<K, V> *x) {
  /*BFS (обход в ширину)
  по факту возвращает дерево по слоям, начиная с вершины x*/
  std::vector<K> tree_vector;
  if (root == nullptr) {
    return tree_vector;
  }
  std::queue<Node<K, V> *> q;
  q.push(root);
  int level{0};
  while (!q.empty()) {
    Node<K, V> *current = q.front();
    q.pop();
    tree_vector.push_back(current->key);
    if (current->left_child != nullptr) {
      q.push(current->left_child);
    }

    if (current->right_child != nullptr) {
      q.push(current->right_child);
    }
  }
  return tree_vector;
}

template <typename K, typename V>
void SplayTree<K, V>::PrintTree() {
  /*выводит всё дерево по слоям*/
  std::vector<K> vector = tree_vector(root);
  for (auto c : vector) {
    std::cout << c << " ";
  }
}

#endif  // SP_TREE_HPP