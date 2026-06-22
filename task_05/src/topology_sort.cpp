#include "topology_sort.hpp"

#include <stack>
#include <vector>
std::vector<int> topology_sort(int N, const std::vector<int>& temperatures) {
  std::stack<int> s;
  std::vector<int> res(N, 0);
  for (int i = 0; i < N; i++) {
    while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
      int last_day = s.top();
      res[last_day] = i - last_day;
      s.pop();
    }
    s.push(i);
  }
  return res;
}
