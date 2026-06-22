
#include <stack>
#include <vector>

std::vector<int> DaysBeforeWarming(int N, std::vector<int>& temperatures) {
  std::vector<int> result(N, 0);
  std::stack<int> st;

  for (int i = 0; i < N; ++i) {
    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
      int prev = st.top();
      st.pop();
      result[prev] = i - prev;
    }
    st.push(i);
  }

  return result;
}