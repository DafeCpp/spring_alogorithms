#include <stack>

#include "warming_func.hpp"

std ::vector<int> Warming(std ::vector<int> temperature) {
  std::stack<int> index;
  std ::vector<int> ans(temperature.size());

  for (int i = 0; i < temperature.size(); ++i) {
    while (!index.empty() && (temperature[i] > temperature[index.top()])) {
      int j = index.top();
      index.pop();
      ans[j] = i - j;
    }
    index.push(i);
  }
  return ans;
}