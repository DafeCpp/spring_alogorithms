#include "table.hpp"
#include <vector>

std::vector<std::string> processQueries(
    const std::vector<std::vector<int>>& table,
    const std::vector<std::pair<int, int>>& queries
) {
    int n = table.size();
    int m = table[0].size();
    
    std::vector<std::vector<int>> bad(n, std::vector<int>(m, 0));
    
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n - 1; ++i) {
            if (table[i][j] > table[i + 1][j]) {
                bad[i][j] = 1;
            }
        }
    }
    
    std::vector<int> maxBad(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int count = 0;
        for (int j = 0; j < m; ++j) {
            count += bad[i][j];
        }
        maxBad[i] = count;
    }
    
    std::vector<std::vector<int>> prefix(n + 1, std::vector<int>(m, 0));
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            prefix[i + 1][j] = prefix[i][j] + (i < n - 1 ? bad[i][j] : 0);
        }
    }
    
    std::vector<std::string> result;
    
    for (const auto& query : queries) {
        int l = query.first - 1;
        int r = query.second - 1;
        
        if (l == r) {
            result.push_back("Yes");
            continue;
        }
        
        bool found = false;
        for (int j = 0; j < m; ++j) {
            int badCount = prefix[r][j] - prefix[l][j];
            if (badCount == 0) {
                found = true;
                break;
            }
        }
        
        result.push_back(found ? "Yes" : "No");
    }
    
    return result;
}