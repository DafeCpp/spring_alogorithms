#include "buy_fish.hpp"

std::vector<int> buy_fish(const std::vector<int>& prices, int k) {
  int N = prices.size();
  std::vector<int> result(N, 0);
  std::deque<int> dq;

  for (int i = 0; i < N; ++i) {
    while (!dq.empty() && dq.front() < i - k + 1) {
      dq.pop_front();
    }

    while (!dq.empty() && prices[dq.back()] >= prices[i]) {
      dq.pop_back();
    }

    dq.push_back(i);

    int bestDay = dq.front();
    result[bestDay]++;
  }

  return result;
}
