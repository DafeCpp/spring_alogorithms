#include <get_border_index.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N;
  vector<int> v;
  string line1, line2;

  getline(cin, line1);
  getline(cin, line2);

  N = stoi(line1);

  istringstream is(line2);
  int x;
  while (is >> x) v.push_back(x);

  cout << get_border_index(v) << endl;
  /*
  if (v[1] == 1) cout << 0 << endl;
  else if (v[N-2] == 0) cout << N-2 << endl;
  else
  {
      int i{(N-1)/2};
      while (v[i] != 0 && v[i+1] != 1)
      {
          if (v[i] == 0)
          {
              if (i+1 < v.size() && v[i+1] == 1)
              {
                  cout << i << endl;
                  break;
              }
              i = (N-1 - i)/2;
          } else
          {
              if (i-1 >= 0  && v[i-1] == 0)
              {
                  cout << i-1 << endl;
                  break;
              }
              i /= 2;
          }
      }
  };
  */
  return 0;
}
