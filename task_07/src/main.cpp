#include <iostream>

#include "KDtree.hpp"
#include "vector"

int main() {
  std::vector<Point> cloud = {
      Point(1.0, 2.0), Point(3.0, 4.0),  Point(5.0, 6.0),
      Point(7.0, 8.0), Point(9.0, 10.0),
  };

  KDTree tree(cloud);
  std ::cout << "compiled\n";
  Point k = tree.NearestPoint(Point(4.8, 5.9));
  std ::cout << k.x << " " << k.y << '\n';
}
