#include <iostream>
#include <vector>

#include "get_k_element.hpp"

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> v;

  for (int i = 0; i < N; ++i) {
    int n;
    cin >> n;
    v.push_back(n);
  }

  int left{0}, right(N - 1);
  cout << get_k_element(v, K, left, right) << endl;
}
