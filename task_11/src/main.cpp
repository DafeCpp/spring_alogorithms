#include <iostream>
#include <string>
#include "finder.hpp"

int main() {
    std::string S, P;
    std::cin >> S >> P;
    std::cout << FindSubSeq(S, P) << std::endl;
}