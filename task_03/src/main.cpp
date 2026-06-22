#include <iostream>
#include <string>
#include "phone.hpp"

int main() {
    std::string s;
    std::cin >> s;
    auto combs = GetCombinations(s);
    for (size_t i = 0; i < combs.size(); ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << combs[i];
    }
    std::cout << std::endl;
    return 0;
}