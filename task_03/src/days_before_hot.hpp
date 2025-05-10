#include <stack>
#include <vector>

struct TemperatureWithDayIndex {
  double temperature;
  int day_index;
};
std::vector<int> DaysBeforeHot(std::vector<double> temperatures);