#include "topology_sort.hpp"
#include <vector>
#include <stack>

std::vector<int> daysUntilWarmer(const std::vector<int>& temperatures) {
  int n = temperatures.size();
  std::vector<int> result(n, 0);
  std::stack<int> st;
  
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
      int prevDay = st.top();
      st.pop();
      result[prevDay] = i - prevDay;
    }
    st.push(i);
  }
  
  return result;
}
