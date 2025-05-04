#ifndef KDtreeHpp
#define KDtreeHpp

#include <memory>
#include <vector>

#include "constants.hpp"

struct Point {
  double x;
  double y;
  Point(double x, double y) : x{x}, y{y} {}
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
  Point NearestPoint(Point target);

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
  enum class Axis {
    Ox = 0,
    Oy = 1,
  };

  void Split(std::unique_ptr<Node>& node, Axis Ax = Axis::Ox, int depth = 0);
  std ::pair<double, double> SAH(Point left_min_point, Point right_max_point,
                                 Axis curr_Axis, std::pair<int, int>& range);
  std::pair<double, Point> FindMinimum(Point target,
                                       std::unique_ptr<Node>& node);
  void PreparePoints(std::vector<Point>& points);
  double Distance(Point first, Point second);
  double DistanceToBox(Point& point, std::pair<Point, Point>& box);
  bool IntoBox(Point target, std::pair<Point, Point> box);

  template <typename T>
  auto GetAxis(const T& request, Axis ax) {
    if (ax == Axis::Ox)
      return request.x;
    else
      return request.y;
  }
};
#endif