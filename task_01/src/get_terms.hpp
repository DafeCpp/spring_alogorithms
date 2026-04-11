#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

pair<int, int> get_terms(vector<int> v, int S) {
  int N = v.size();

  if (N == 0 || N == 1) return pair(-1, -1);

  int l{0}, r{N - 1};

  int s;
  while (l != r) {
    s = v[l] + v[r];
    if (s == S) {
      return pair(v[l], v[r]);
    } else {
      if (s > S)
        --r;
      else
        ++l;
    }
  }

  return pair(-1, -1);
}