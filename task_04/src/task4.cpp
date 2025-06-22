#include "task4.hpp"

std::vector<int> BuyFish(std::vector<int> price_list, int period) {
  if (price_list.size() == 0) {
    return {};
  }
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      fish_heap;

  std::vector<int> fish_in_days(price_list.size(), 0);

  for (int day{0}; day < price_list.size(); ++day) {
    fish_heap.push(std::pair<int, int>(price_list[day], day));

    while (!fish_heap.empty() && fish_heap.top().second + period <= day) {
      fish_heap.pop();
    }
    auto [best_price, best_day] = fish_heap.top();
    fish_in_days[best_day]++;
  }
  return fish_in_days;
}