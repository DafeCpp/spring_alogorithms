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
  return 0;
}
