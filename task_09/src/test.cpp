#include <vector>
#include <iostream>

void solve_table_problem(std::istream& in, std::ostream& out) {
    int n, m;
    in >> n >> m;
    
    std::vector<std::vector<int>> table(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            in >> table[i][j];
        }
    }

    std::vector<std::vector<int>> prefix(m, std::vector<int>(n, 0));
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            int add_value = 0;
            if (table[i-1][j] <= table[i][j]) {
                add_value = 1;
            }
            prefix[j][i] = prefix[j][i-1] + add_value;
        }
    }

    int k;
    in >> k;
    while (k--) {
        int l, r;
        in >> l >> r;
        
        if (l == r) {
            out << "Yes\n";
            continue;
        }
        
        bool found_good = false;
        int need_count = r - l;
        
        for (int j = 0; j < m; j++) {
            int total_good = prefix[j][r-1] - prefix[j][l-1];
            if (total_good == need_count) {
                found_good = true;
                break;
            }
        }
        
        if (found_good) {
            out << "Yes\n";
        } else {
            out << "No\n";
        }
    }
}