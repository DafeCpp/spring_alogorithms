#include <get_terms.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int S, N;
  vector<int> v;
  string line3, line1, line2;

  getline(cin, line1);
  getline(cin, line2);
  getline(cin, line3);

  S = stoi(line1);
  N = stoi(line2);

  istringstream is(line3);

  int x;
  while (is >> x) v.push_back(x);
  pair<int, int> result = get_terms(v, S);
  if (result == pair(-1, -1))
    cout << -1 << endl;
  else
    cout << result.first << " " << result.second << endl;
  /*
  python3 ./scripts/run_cases.py --tasks task_01
  int l{0}, r{N-1};

  int s;
  while (l != r)
  {
      s = v[l] + v[r];
      if (s == S)
      {
          cout << v[l] << " " << v[r] << endl;
          break;
      }
      else
      {
          if (s > S) --r;
          else ++l;
      }
  }

  if (l == r) cout << -1 << endl;
  */
  return 0;
}
