#include "AVLTree.h"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() { DeleteTree(root); }

int AVLTree::Height(AVLTree::Node* p) { return p ? p->height : 0; }

int AVLTree::BFactor(AVLTree::Node* p) {
  return Height(p->right) - Height(p->left);
}

void AVLTree::FixHeight(AVLTree::Node* p) {
  int hl = Height(p->left);
  int hr = Height(p->right);
  p->height = (hl > hr ? hl : hr) + 1;
}

AVLTree::Node* AVLTree::RotateRight(AVLTree::Node* p) {
  AVLTree::Node* q = p->left;
  p->left = q->right;
  q->right = p;
  FixHeight(p);
  FixHeight(q);
  return q;
}

AVLTree::Node* AVLTree::RotateLeft(AVLTree::Node* q) {
  AVLTree::Node* p = q->right;
  q->right = p->left;
  p->left = q;
  FixHeight(q);
  FixHeight(p);
  return p;
}

AVLTree::Node* AVLTree::Balance(AVLTree::Node* p) {
  FixHeight(p);

  if (BFactor(p) == 2) {
    if (BFactor(p->right) < 0) {
      p->right = RotateRight(p->right);
    }
    return RotateLeft(p);
  }

  if (BFactor(p) == -2) {
    if (BFactor(p->left) > 0) {
      p->left = RotateLeft(p->left);
    }
    return RotateRight(p);
  }

  return p;
}

AVLTree::Node* AVLTree::InsertNode(AVLTree::Node* p, int k) {
  if (!p) return new AVLTree::Node(k);

  if (k < p->key) {
    p->left = InsertNode(p->left, k);
  } else if (k > p->key) {
    p->right = InsertNode(p->right, k);
  } else {
    return p;
  }

  return Balance(p);
}

AVLTree::Node* AVLTree::FindMin(AVLTree::Node* p) {
  return p->left ? FindMin(p->left) : p;
}

AVLTree::Node* AVLTree::RemoveMin(AVLTree::Node* p) {
  if (p->left == nullptr) return p->right;
  p->left = RemoveMin(p->left);
  return Balance(p);
}

AVLTree::Node* AVLTree::RemoveNode(AVLTree::Node* p, int k) {
  if (!p) return nullptr;

  if (k < p->key) {
    p->left = RemoveNode(p->left, k);
  } else if (k > p->key) {
    p->right = RemoveNode(p->right, k);
  } else {
    AVLTree::Node* q = p->left;
    AVLTree::Node* r = p->right;
    delete p;

    if (!r) return q;

    AVLTree::Node* min = FindMin(r);
    min->right = RemoveMin(r);
    min->left = q;

    return Balance(min);
  }
  return Balance(p);
}

void AVLTree::DeleteTree(AVLTree::Node* p) {
  if (p != nullptr) {
    DeleteTree(p->left);
    DeleteTree(p->right);

    delete p;
  }
}

void AVLTree::Insert(int key) { root = InsertNode(root, key); }

void AVLTree::Remove(int key) { root = RemoveNode(root, key); }

bool AVLTree::Find(int key) {
  AVLTree::Node* current = root;
  while (current) {
    if (current->key == key) return true;
    current = (key < current->key) ? current->left : current->right;
  }
  return false;
}
