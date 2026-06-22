#include "task6.hpp"

#include <deque>
#include <vector>

int totalfishcost(int N, int K, std::vector<int>& fishcost) {
  long long totalcost = 0;

  std::deque<int> window;

  for (int i = 0; i < N; i++) {
    if (!window.empty() && window.front() < i - K + 1) {
      window.pop_front();
    }

    while (!window.empty() && fishcost[window.back()] >= fishcost[i]) {
      window.pop_back();
    }

    window.push_back(i);

    totalcost += fishcost[window.front()];
  }

  return totalcost;
}
