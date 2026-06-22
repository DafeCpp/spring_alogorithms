#include <algorithm>
#include <cmath>
#include <iostream>
#include <task9.hpp>
#include <vector>

void Point::print() const {
  for (size_t i = 0; i < coordinates.size(); ++i) {
    std::cout << coordinates[i] << (i == coordinates.size() - 1 ? "" : " ");
  }
}

Node::Node(Point p, int a) {
  point = p;
  axis = a;
  left = nullptr;

  right = nullptr;
}

Node* buildTree(std::vector<Point>& points, int left, int right, int k,
                int depth) {
  if (left > right) {
    return nullptr;
  }

  int axis = depth % k;

  std::sort(points.begin() + left, points.begin() + right + 1,
            [axis](const Point& a, const Point& b) {
              return a.coordinates[axis] < b.coordinates[axis];
            });

  int median = left + (right - left) / 2;

  Node* node = new Node(points[median], axis);
  node->left = buildTree(points, left, median - 1, k, depth + 1);
  node->right = buildTree(points, median + 1, right, k, depth + 1);

  return node;
}

double distance(const std::vector<double>& a, const std::vector<double>& b,
                int k) {
  double dist = 0;
  for (int i = 0; i < k; i++) {
    dist += (a[i] - b[i]) * (a[i] - b[i]);
  }
  return dist;
}

void findNeighbors(Node* root, const std::vector<double>& X, double r, int k,
                   std::vector<Point>& result) {
  if (root == nullptr) {
    return;
  }

  double dist_X = distance(root->point.coordinates, X, k);
  if (dist_X <= r * r) {
    result.push_back(root->point);
  }

  int axis = root->axis;
  double diff = X[axis] - root->point.coordinates[axis];

  if (diff < 0) {
    findNeighbors(root->left, X, r, k, result);
    if (diff * diff <= r * r) {
      findNeighbors(root->right, X, r, k, result);
    }
  } else {
    findNeighbors(root->right, X, r, k, result);
    if (diff * diff <= r * r) {
      findNeighbors(root->left, X, r, k, result);
    }
  }
}
