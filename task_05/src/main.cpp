#include <iostream>
#include <vector>

#include "topology_sort.hpp"

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> v;

  for (int i = 0; i < N; ++i) {
    int n;
    cin >> n;
    v.push_back(n);
  }
  vector<int> v2 = temperature_rise(v);
  for (int t : v2) cout << t << " ";
}
