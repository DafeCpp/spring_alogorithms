#include "topology_sort.hpp"

std::vector<int> days_until_warmer(const std::vector<int>& temperatures) {
  int n = temperatures.size();
  std::vector<int> result(n, 0);
  std::stack<int> st;

  for (int i = 0; i < n; ++i) {
    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
      int prev_index = st.top();
      st.pop();
      result[prev_index] = i - prev_index;
    }
    st.push(i);
  }

  return result;
}
