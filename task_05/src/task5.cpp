#include "task5.hpp"

#include <stack>

std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
  int n = temperatures.size();
  std::vector<int> ans(n, 0);
  std::stack<int> s;

  for (int i = 0; i < n; ++i) {
    while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
      int idx = s.top();
      s.pop();
      ans[idx] = i - idx;
    }
    s.push(i);
  }

  return ans;
}
