#include <iostream>
#include <vector>

#include "util.hpp"

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> prices(N);
  for (int i = 0; i < N; i++) {
    cin >> prices[i];
  }

  int result = func(N, K, prices);
  cout << result << endl;

  return 0;
}