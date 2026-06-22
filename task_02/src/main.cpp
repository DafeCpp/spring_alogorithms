#include <get_border_index.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  int N;
  std::vector<int> v;
  std::string line1, line2;

  getline(std::cin, line1);
  getline(std::cin, line2);

  N = stoi(line1);

  std::istringstream is(line2);
  int x;
  while (is >> x) v.push_back(x);

  std::cout << GetBorderIndex(v) << std::endl;
  return 0;
}
