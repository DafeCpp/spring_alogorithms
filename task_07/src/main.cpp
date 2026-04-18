#include <iostream>
#include <merge_sort.hpp>
#include <vector>

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
  vector<int> v_sorted = MergeSort(v);

  for (int i = 0; i < N; ++i) cout << v_sorted[i] << " ";
}
