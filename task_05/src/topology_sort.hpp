#include <vector>

using namespace std;

vector<int> temperature_rise(vector<int> v1) {
  vector<int> stack, v2(v1.size(), 0);

  size_t i = 0;
  while (i < v1.size()) {
    if (stack.size() == 0) {
      stack.push_back(i);
      ++i;
    } else if (v1[i] > v1[stack.back()]) {
      v2[stack.back()] = i - stack.back();
      stack.pop_back();
    } else {
      stack.push_back(i);
      ++i;
    }
  }
  return v2;
}