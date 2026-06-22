#include <gtest/gtest.h>

#include <vector>

#include "task9.hpp"

void freeTree(Node* root) {
  if (!root) return;

  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

TEST(KDTree, DistanceCalculation) {
  std::vector<double> a{0.0, 0.0};
  std::vector<double> b{3.0, 4.0};
  ASSERT_DOUBLE_EQ(25.0, distance(a, b, 2));
}

TEST(KDTree, FindNeighbors2D) {
  std::vector<Point> points = {
      {{1.0, 1.0}}, {{2.0, 2.0}}, {{5.0, 5.0}}, {{9.0, 9.0}}};

  Node* root = buildTree(points, 0, points.size() - 1, 2, 0);

  std::vector<double> target{2.0, 1.0};
  double radius = 2.0;
  std::vector<Point> result;

  findNeighbors(root, target, radius, 2, result);

  ASSERT_EQ(2, result.size());

  ASSERT_NEAR(2.0, result[0].coordinates[0], 1e-9);
  ASSERT_NEAR(2.0, result[0].coordinates[1], 1e-9);

  freeTree(root);
}

TEST(KDTree, NoNeighborsFound) {
  std::vector<Point> points = {{{10.0, 10.0}}, {{20.0, 20.0}}};
  Node* root = buildTree(points, 0, points.size() - 1, 2, 0);

  std::vector<double> target{0.0, 0.0};
  double radius = 1.0;
  std::vector<Point> result;

  findNeighbors(root, target, radius, 2, result);

  ASSERT_TRUE(result.empty());

  freeTree(root);
}

TEST(KDTree, EmptyTree) {
  std::vector<Point> points;
  Node* root = buildTree(points, 0, points.size() - 1, 2, 0);

  ASSERT_EQ(nullptr, root);
}
