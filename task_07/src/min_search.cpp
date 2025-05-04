#include <algorithm>

#include "KDtree.hpp"

double KDTree::Distance(Point first, Point second) {
  return ((first.x - second.x) * (first.x - second.x) +
          (first.y - second.y) * (first.y - second.y));
}

bool KDTree::IntoBox(Point target, std::pair<Point, Point> box) {
  if ((target.x >= box.first.x) && (target.x <= box.second.x)) {
    if ((target.y >= box.first.y) && (target.y <= box.second.y)) return true;
  }
  return false;
}

double KDTree::DistanceToBox(Point& point, std::pair<Point, Point>& box) {
  double dx = std::max({box.first.x - point.x, 0.0, point.x - box.second.x});
  double dy = std::max({box.first.y - point.y, 0.0, point.y - box.second.y});
  return dx * dx + dy * dy;
}

std::pair<double, Point> KDTree::FindMinimum(Point target,
                                              std::unique_ptr<Node>& node) {
  if (node->leaf) {
    double min_dist = NONE;
    Point NearestPoint;
    for (int i = node->indices.first; i <= node->indices.second; ++i) {
      double current_dist = Distance(cloud[i], target);
      if (current_dist < min_dist) {
        min_dist = current_dist;
        NearestPoint = cloud[i];
      }
    }
    return {min_dist, NearestPoint};
  }

  bool target_in_left = IntoBox(target, node->left_child->bounding_box);
  auto& first_child = target_in_left ? node->left_child : node->right_child;
  auto& second_child = target_in_left ? node->right_child : node->left_child;

  auto [min_dist, nearest] = FindMinimum(target, first_child);

  double dist_to_second_box = DistanceToBox(target, second_child->bounding_box);
  if (dist_to_second_box < min_dist) {
    auto [second_dist, second_nearest] = FindMinimum(target, second_child);
    if (second_dist < min_dist) {
      min_dist = second_dist;
      nearest = second_nearest;
    }
  }

  return {min_dist, nearest};
}

Point KDTree::NearestPoint(Point target) {
  auto point = FindMinimum(target, root);
  return point.second;
}