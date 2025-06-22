#include "fish.hpp"
#include <vector>
#include <stack>

std::pair<long long, std::vector<int>> solve(int N, int K, std::vector<int> prices) {
    if (N == 0) {
        return {0, {}};
    }

    std::vector<int> next_cheaper(N);
    std::stack<int> st;

    for (int i = 0; i < N; ++i) {
        while (!st.empty() && prices[i] < prices[st.top()]) {
            next_cheaper[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        int i = st.top();
        st.pop();
        next_cheaper[i] = i + K;
    }

    std::vector<int> buy(N, 0);
    long long total_cost = 0;
    int i = 0;
    while (i < N) {
        int cover = next_cheaper[i] - i;
        if (cover > K) cover = K;
        if (cover > N - i) cover = N - i;
        buy[i] = cover;
        total_cost += static_cast<long long>(prices[i]) * cover;
        i += cover;
    }

    return {total_cost, buy};
}