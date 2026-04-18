#include <iostream>
#include <vector>

#include "temperature_rise.hpp"

int main() {
  int N;
  std::cin >> N;
  std::vector<int> v;

  for (int i = 0; i < N; ++i) {
    int n;
    std::cin >> n;
    v.push_back(n);
  }
  std::vector<int> v2 = TemperatureRise(v);
  for (int t : v2) std::cout << t << " ";
}
