#include <iostream>
#include <vector>
#include "coin.hpp"

int main() {
    int S, N;
    std::cin >> S >> N;
    std::vector<int> coins(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> coins[i];
    }
    std::cout << MinCoins(S, coins) << std::endl;
}