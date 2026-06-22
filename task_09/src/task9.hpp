#pragma once

#include <vector>

struct Point {
  std::vector<double> coordinates;

  void print() const;
};

struct Node {
  Point point;
  Node* left = nullptr;
  Node* right = nullptr;
  int axis;

  Node(Point p, int a);
};

Node* buildTree(std::vector<Point>& points, int left, int right, int k,
                int depth);
double distance(const std::vector<double>& a, const std::vector<double>& b,
                int k);
void findNeighbors(Node* root, const std::vector<double>& X, double r, int k,
                   std::vector<Point>& result);
