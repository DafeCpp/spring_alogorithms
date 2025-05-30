#include <iostream>
#include <vector>
#include <stack>
using namespace std;

static vector<int> dailyTemp(const vecror<int>& temp){
  int n = temp.size();
  vector<int> res(n, 0);
  stack<int> s;

  for(int i = 0; i<n; ++i)
  {
    while(!s.empty() && temp[i]>temp[s.top()])
    {
      int prev_d = s.top();
      s.pop();
      res[prev_d] = 1 - prev_d;
    }
    s.push(i);
  }
  return res;
}
int main() { return 0; }
