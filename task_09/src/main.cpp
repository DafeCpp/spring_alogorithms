#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> table[i][j];
        }
    }
    
    vector<vector<bool>> col_sorted(m, vector<bool>(n));
    for (int j = 0; j < m; ++j) {
        col_sorted[j][0] = true;
        for (int i = 1; i < n; ++i) {
            col_sorted[j][i] = col_sorted[j][i-1] && (table[i-1][j] <= table[i][j]);
        }
    }
    
    vector<vector<int>> segment_start(m, vector<int>(n));
    for (int j = 0; j < m; ++j) {
        segment_start[j][0] = 0;
        for (int i = 1; i < n; ++i) {
            if (table[i-1][j] <= table[i][j]) {
                segment_start[j][i] = segment_start[j][i-1];
            } else {
                segment_start[j][i] = i;
            }
        }
    }
    
    vector<int> row_max_good(n);
    for (int i = 0; i < n; ++i) {
        int max_good = -1;
        for (int j = 0; j < m; ++j) {
            if (segment_start[j][i] <= i) {
                max_good = max(max_good, segment_start[j][i]);
            }
        }
        row_max_good[i] = max_good;
    }
    
    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        
        if (l >= r) {
            cout << "Yes\n";
            continue;
        }
        
        if (row_max_good[r] <= l) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}