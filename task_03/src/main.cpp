#include <iostream>

#include "phone_algorithm.hpp"

int main() {
  std::string number;
  std::cin >> number;
  auto res = PhoneAlgorithm(number);
  for (auto elem : res) {
    std::cout << elem << ' ';
  }
}
