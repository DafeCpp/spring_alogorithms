#include "days_untill_warmer.hpp"

#include <stdexcept>

std::vector<int> DaysUntilWarmer(const std::vector<int>& temperatures) {
  int n = temperatures.size();
  if (n == 0) {
    throw std::runtime_error("Empty array");
  }
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
