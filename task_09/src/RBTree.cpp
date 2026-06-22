#include "RBTree.hpp"

void RBtree::initEmptyNode(Node* node, Node* parent) {
  node->data = 0;
  node->color = black;
  node->left = nullptr;
  node->right = nullptr;
  node->parent = parent;
}

void RBtree::leftRotate(Node* x) {
  Node* y = x->right;
  x->right = y->left;
  if (y->left != TNULL) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nullptr) {
    this->root = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

void RBtree::rightRotate(Node* x) {
  Node* y = x->left;
  x->left = y->right;
  if (y->right != TNULL) {
    y->right->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nullptr) {
    this->root = y;
  } else if (x == x->parent->right) {
    x->parent->right = y;
  } else {
    x->parent->left = y;
  }
  y->right = x;
  x->parent = y;
}

void RBtree::insertBalance(Node* k) {
  Node* u;
  while (k->parent->color == red) {
    if (k->parent == k->parent->parent->right) {
      u = k->parent->parent->left;
      if (u->color == red) {
        u->color = black;
        k->parent->color = black;
        k->parent->parent->color = red;
        k = k->parent->parent;
      } else {
        if (k == k->parent->left) {
          k = k->parent;
          rightRotate(k);
        }
        k->parent->color = black;
        k->parent->parent->color = red;
        leftRotate(k->parent->parent);
      }
    } else {
      u = k->parent->parent->right;
      if (u->color == red) {
        u->color = black;
        k->parent->color = black;
        k->parent->parent->color = red;
        k = k->parent->parent;
      } else {
        if (k == k->parent->right) {
          k = k->parent;
          leftRotate(k);
        }
        k->parent->color = black;
        k->parent->parent->color = red;
        rightRotate(k->parent->parent);
      }
    }
    if (k == root) break;
  }
  root->color = black;
}

void RBtree::rbChange(Node* u, Node* v) {
  if (u->parent == nullptr) {
    root = v;
  } else if (u == u->parent->left) {
    u->parent->left = v;
  } else {
    u->parent->right = v;
  }
  v->parent = u->parent;
}

Node* RBtree::minimum(Node* node) {
  while (node->left != TNULL) {
    node = node->left;
  }
  return node;
}

void RBtree::deleteBalance(Node* x) {
  Node* s;
  while (x != root && x->color == black) {
    if (x == x->parent->left) {
      s = x->parent->right;
      if (s->color == red) {
        s->color = black;
        x->parent->color = red;
        leftRotate(x->parent);
        s = x->parent->right;
      }
      if (s->left->color == black && s->right->color == black) {
        s->color = red;
        x = x->parent;
      } else {
        if (s->right->color == black) {
          s->left->color = black;
          s->color = red;
          rightRotate(s);
          s = x->parent->right;
        }
        s->color = x->parent->color;
        x->parent->color = black;
        s->right->color = black;
        leftRotate(x->parent);
        x = root;
      }
    } else {
      s = x->parent->left;
      if (s->color == red) {
        s->color = black;
        x->parent->color = red;
        rightRotate(x->parent);
        s = x->parent->left;
      }
      if (s->right->color == black && s->right->color == black) {
        s->color = red;
        x = x->parent;
      } else {
        if (s->left->color == black) {
          s->right->color = black;
          s->color = red;
          leftRotate(s);
          s = x->parent->left;
        }
        s->color = x->parent->color;
        x->parent->color = black;
        s->left->color = black;
        rightRotate(x->parent);
        x = root;
      }
    }
  }
  x->color = black;
}

void RBtree::deleteNodeKey(Node* node, int key) {
  Node* z = TNULL;
  Node* x;
  Node* y;

  while (node != TNULL) {
    if (node->data == key) {
      z = node;
      break;
    }
    if (node->data <= key) {
      node = node->right;
    } else {
      node = node->left;
    }
  }
  if (z == TNULL) {
    return;
  }

  y = z;
  int yOriginalColor = y->color;
  if (z->left == TNULL) {
    x = z->right;
    rbChange(z, z->right);
  } else if (z->right == TNULL) {
    x = z->left;
    rbChange(z, z->left);
  } else {
    y = minimum(z->right);
    yOriginalColor = y->color;
    x = y->right;
    if (y->parent == z) {
      x->parent = y;
    } else {
      rbChange(y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    rbChange(z, y);
    y->left = z->left;
    y->left->parent = y;
    y->color = z->color;
  }
  delete z;
  if (yOriginalColor == black) {
    deleteBalance(x);
  }
}

RBtree::RBtree() {
  TNULL = new Node(0);
  TNULL->color = black;
  root = TNULL;
}

void RBtree::Insert(int key) {
  if (Find(key)) return;

  Node* node = new Node(key);
  node->parent = nullptr;
  node->data = key;
  node->left = TNULL;
  node->right = TNULL;
  node->color = red;

  Node* y = nullptr;
  Node* x = this->root;

  while (x != TNULL) {
    y = x;
    if (node->data < x->data) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  node->parent = y;
  if (y == nullptr) {
    root = node;
  } else if (node->data < y->data) {
    y->left = node;
  } else {
    y->right = node;
  }

  if (node->parent == nullptr) {
    node->color = black;
    return;
  }
  if (node->parent->parent == nullptr) {
    return;
  }
  insertBalance(node);
}

bool RBtree::Find(int key) {
  Node* curr = root;
  while (curr != TNULL) {
    if (key == curr->data) {
      return true;
    } else if (key < curr->data) {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
  }
  return false;
}

void RBtree::Remove(int key) { deleteNodeKey(this->root, key); }

void RBtree::destroyTree(Node* node) {
  if (node != TNULL) {
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
  }
}

RBtree::~RBtree() {
  destroyTree(root);
  delete TNULL;
}