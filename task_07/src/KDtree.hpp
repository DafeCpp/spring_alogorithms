#ifndef KDtreeHpp
#define KDtreeHpp

#include <memory>
#include <vector>

#include "constants.hpp"

struct Point {
  double x;
  double y;
  Point(double xx, double yy) : x{xx}, y{yy} {}
  Point() : x{NONE}, y{NONE} {}

  bool operator==(const Point& other) const {
    constexpr double epsilon = 1e-9;
    return (std::abs(x - other.x) < epsilon) &&
           (std::abs(y - other.y) < epsilon);
  }
};

class KDTree {
 public:
  KDTree(std::vector<Point> points);
  ~KDTree() = default;
  Point nearest_point(Point target);

 private:
  std ::vector<Point> cloud;

  struct Node {
    bool leaf = false;
    std::unique_ptr<Node> left_child = nullptr;
    std::unique_ptr<Node> right_child = nullptr;
    std::pair<Point, Point> bounding_box =
        std::make_pair(Point(0, 0), Point(0, 0));
    std ::pair<int, int> indices;  // промежуток точек
                                   // принадлежащих данной bounding_box [от, до]
  };
  std::unique_ptr<Node> root;
  enum class axis {
    Ox = 0,
    Oy = 1,
  };

  void split(std::unique_ptr<Node>& node, axis Ax = axis::Ox, int depth = 0);
  std ::pair<double, double> SAH(Point left_min_point, Point right_max_point,
                                 axis curr_axis, std::pair<int, int>& range);
  std::pair<double, Point> find_minimum(Point target,
                                        std::unique_ptr<Node>& node);
  void prepare_points(std::vector<Point>& points);
  double distance(Point first, Point second);
  double distanceToBox(Point& point, std::pair<Point, Point>& box);
  bool into_box(Point target, std::pair<Point, Point> box);

  template <typename T>
  auto get_axis(const T& request, axis ax) {
    if (ax == axis::Ox)
      return request.x;
    else
      return request.y;
  }
};
#endif