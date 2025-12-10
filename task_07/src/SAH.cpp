#include <omp.h>

#include <algorithm>

#include "KDtree.hpp"
#include "constants.hpp"

std::pair<double, double> KDTree::SAH(Point left_min_point,
                                      Point right_max_point, Axis curr_axis,
                                      std::pair<int, int>& range) {
  std::pair<double, double> SAH_result{NONE, NONE};
  double width =
      GetAxis(right_max_point, curr_axis) - GetAxis(left_min_point, curr_axis);
  double width_x = right_max_point.x - left_min_point.x;
  double width_y = right_max_point.y - left_min_point.y;
  double width_w = curr_axis == Axis::Ox ? width_y : width_x;
  double SApar = width_x * width_y;

  if (SApar <= 0) return SAH_result;

  const int bins = PARITION;
  std::vector<int> binCounts(bins, 0);

  double bin_width = width / bins;
  if (bin_width <= 0) return SAH_result;

  for (int index = range.first; index <= range.second; ++index) {
    int bin_index = static_cast<int>((GetAxis(cloud[index], curr_axis) -
                                      GetAxis(left_min_point, curr_axis)) /
                                     bin_width);
    bin_index = std::clamp(bin_index, 0, bins - 1);
    ++binCounts[bin_index];
  }

  std::vector<int> prefix_sum(bins + 1, 0);
  for (int i = 1; i <= bins; ++i) {
    prefix_sum[i] = prefix_sum[i - 1] + binCounts[i - 1];
  }

  for (int i = 1; i < bins; ++i) {
    double x0 = GetAxis(left_min_point, curr_axis) + width * i / bins;
    double SAl = (x0 - GetAxis(left_min_point, curr_axis)) * width_w;
    double SAr = (GetAxis(right_max_point, curr_axis) - x0) * width_w;

    int Nl = prefix_sum[i];
    int Nr = (range.second - range.first + 1) - Nl;

    double SAH = Ct + Ci * (SAl * Nl + SAr * Nr) / SApar;
    if ((SAH < SAH_result.first) || (SAH_result.first < 0)) {
      SAH_result = std::make_pair(SAH, x0);
    }
  }

  return SAH_result;
}