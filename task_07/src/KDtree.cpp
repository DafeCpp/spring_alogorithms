#include "KDtree.hpp"

#include <omp.h>

#include <algorithm>
#include <execution>
#include <stdexcept>

#include "constants.hpp"

void KDTree::prepare_points(std::vector<Point>& points) {
  std::sort(std::execution::par, points.begin(), points.end(),
            [](const Point& a, const Point& b) {
              return std::tie(a.x, a.y) < std::tie(b.x, b.y);
            });

  auto equal = [](const Point& a, const Point& b) {
    return a.x == b.x && a.y == b.y;
  };
  points.erase(std::unique(points.begin(), points.end(), equal), points.end());
}

void KDTree::split(std::unique_ptr<Node>& node, axis Ax, int depth) {
  std ::pair<double, double> SAH = KDTree::SAH(
      node->bounding_box.first, node->bounding_box.second, Ax, node->indices);

  double SAH_parant = Ci * (node->indices.second - node->indices.first);

  if (SAH.first >= SAH_parant) {
    node->leaf = true;
    return;
  }

  node->left_child = std::make_unique<Node>();
  node->right_child = std::make_unique<Node>();

  if (Ax == axis::Ox) {
    node->left_child->bounding_box.first = node->bounding_box.first;
    node->left_child->bounding_box.second =
        Point(SAH.second, node->bounding_box.second.y);
    node->right_child->bounding_box.first =
        Point(SAH.second, node->bounding_box.first.y);
    node->right_child->bounding_box.second = node->bounding_box.second;
  } else {
    node->right_child->bounding_box.first =
        Point(node->bounding_box.first.x, SAH.second);
    node->right_child->bounding_box.second = node->bounding_box.second;

    node->left_child->bounding_box.first = node->bounding_box.first;
    node->left_child->bounding_box.second =
        Point(node->bounding_box.second.x, SAH.second);
  }

  node->left_child->indices.first = node->indices.first;

  int left_count = std::count_if(
      std::execution::par, cloud.begin() + node->indices.first,
      cloud.begin() + node->indices.second + 1,
      [Ax, split_pos = SAH.second](const Point& p) {
        return (Ax == axis::Ox) ? p.x < split_pos : p.y < split_pos;
      });

  node->left_child->indices.second = node->indices.first + left_count - 1;
  node->right_child->indices.first = node->indices.first + left_count;
  node->right_child->indices.second = node->indices.second;

  Ax == axis::Ox ? Ax = axis::Oy : Ax = axis::Ox;

  if (depth < max_parallel_depth) {
#pragma omp task shared(node)
    split(node->left_child, Ax, depth + 1);

#pragma omp task shared(node)
    split(node->right_child, Ax, depth + 1);

#pragma omp taskwait
  } else {
    split(node->left_child, Ax, depth + 1);
    split(node->right_child, Ax, depth + 1);
  }
}

KDTree::KDTree(std ::vector<Point> points) {
  if (points.size() == 0) throw std::invalid_argument{"No Points detected"};

  cloud = std::move(points);
  prepare_points(cloud);
  
  root = std::make_unique<Node>();
  root->indices = std::make_pair(0, cloud.size() - 1);
  root->bounding_box = std::make_pair(cloud[0], cloud[cloud.size() - 1]);

#pragma omp parallel
  {
#pragma omp single nowait
    split(root, axis::Ox, 0);
  }
}
