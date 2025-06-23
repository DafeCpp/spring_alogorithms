#include "solution.hpp"

#include <algorithm>
#include <vector>

std::vector<int> FishPerDay(std::vector<int> prices, int k) {
  // the fish can't lay for more than prices.size() days
  k = std::min((int)prices.size(), k);
  std::vector<int> res(prices.size());
  MinQueue queue;

  int day = 0;

  for (; day < k; ++day) {
    queue.Push(prices[day]);
    res[queue.GetMinPos()] += 1;
  }

  for (; day < prices.size(); ++day) {
    queue.Pull();
    queue.Push(prices[day]);
    res[queue.GetMinPos()] += 1;
  }

  return res;
}
