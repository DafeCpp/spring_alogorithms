#include <iostream>
#include <deque>
#include <utility>
#include <vector>

using namespace std;

static vector<pair<int, int>> bFish(const vector<int>& prices, int k){
  int n = prices.size();
  vector<pair<int, int>> purchases;
  deque<int> dq;

  for(int i=0; i<n; ++i){
    while(!dq.empty() && dq.front() < i-k+1)
    while(!dq.empty() && prices[i]<=prices[dq.back()]){
      dq.pop_back();
    }
    dq.push_back(i);
    
    if (dq.front()==1)
    {
      int buy_d = min(k, n-1);
      purchases.emplace_back(i, buy_d);
      i += buy_d -1;
      dq.clear();
    }

  }
  return purchases;
}

int main() { return 0; }
