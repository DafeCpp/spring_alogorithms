#include <get_terms.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// python3 ./scripts/run_cases.py --tasks task_01

int main() {
  int S, N;
  std::vector<int> v;
  std::string line3, line1, line2;

  getline(std::cin, line1);
  getline(std::cin, line2);
  getline(std::cin, line3);

  S = stoi(line1);
  N = stoi(line2);

  std::istringstream is(line3);

  int x;
  while (is >> x) v.push_back(x);
  std::pair<int, int> result = GetTerms(v, S);
  if (result == std::pair(-1, -1))
    std::cout << -1 << std::endl;
  else
    std::cout << result.first << " " << result.second << std::endl;
  return 0;
}
