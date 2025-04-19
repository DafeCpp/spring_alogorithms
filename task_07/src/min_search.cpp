#include <algorithm>

#include "KDtree.hpp"

double KDTree::distance(Point first, Point second) {
  return ((first.x - second.x) * (first.x - second.x) +
          (first.y - second.y) * (first.y - second.y));
}

bool KDTree::into_box(Point target, std::pair<Point, Point> box) {
  if ((target.x >= box.first.x) && (target.x <= box.second.x)) {
    if ((target.y >= box.first.y) && (target.y <= box.second.y)) return true;
  }
  return false;
}

double KDTree::distanceToBox(Point& point, std::pair<Point, Point>& box) {
  double dx = std::max({box.first.x - point.x, 0.0, point.x - box.second.x});
  double dy = std::max({box.first.y - point.y, 0.0, point.y - box.second.y});
  return dx * dx + dy * dy;
}

std::pair<double, Point> KDTree::find_minimum(Point target,
                                              std::unique_ptr<Node>& node) {
  if (node->leaf) {
    double min_dist = NONE;
    Point nearest_point;
    for (int i = node->indices.first; i <= node->indices.second; ++i) {
      double current_dist = distance(cloud[i], target);
      if (current_dist < min_dist) {
        min_dist = current_dist;
        nearest_point = cloud[i];
      }
    }
    return {min_dist, nearest_point};
  }

  bool target_in_left = into_box(target, node->left_child->bounding_box);
  auto& first_child = target_in_left ? node->left_child : node->right_child;
  auto& second_child = target_in_left ? node->right_child : node->left_child;

  auto [min_dist, nearest] = find_minimum(target, first_child);

  double dist_to_second_box = distanceToBox(target, second_child->bounding_box);
  if (dist_to_second_box < min_dist) {
    auto [second_dist, second_nearest] = find_minimum(target, second_child);
    if (second_dist < min_dist) {
      min_dist = second_dist;
      nearest = second_nearest;
    }
  }

  return {min_dist, nearest};
}

Point KDTree::nearest_point(Point target) {
  auto point = find_minimum(target, root);
  return point.second;
}