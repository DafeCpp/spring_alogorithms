#include <get_combinations.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string digits;
  getline(cin, digits);

  vector<string> result = get_combinations(digits);

  for (string str : result) cout << str << " ";
}
