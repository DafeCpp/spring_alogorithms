#include <iostream>
#include "solution.hpp"

int main() {
    std::string s;
    std::cin >> s;
    for (const auto& el : ButtonPhone(s)) {
        std::cout << el << " ";
    }
}