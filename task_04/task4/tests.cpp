#include "fish.hpp"
#include <iostream>
#include <vector>
#include <cassert>

void test1() {
    int N = 3, K = 2;
    std::vector<int> prices = {1, 2, 3};
    auto [cost, buy] = solve(N, K, prices);
    assert(cost == 5);
    assert(buy == std::vector<int>({2, 0, 1}));
}

void test2() {
    int N = 3, K = 2;
    std::vector<int> prices = {3, 2, 1};
    auto [cost, buy] = solve(N, K, prices);
    assert(cost == 6);
    assert(buy == std::vector<int>({1, 1, 1}));
}

void test3() {
    int N = 3, K = 3;
    std::vector<int> prices = {1, 3, 2};
    auto [cost, buy] = solve(N, K, prices);
    assert(cost == 3);
    assert(buy == std::vector<int>({3, 0, 0}));
}
int main() {
    test1();
    test2();
    test3();
    return 0;
}