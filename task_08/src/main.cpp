int main() { return 0; }
/*
#include <vector>
#include <iostream>

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
    
    // Для каждого столбца создаем массив, где отмечаем, отсортированы ли строки i и i+1
    vector<vector<bool>> sorted_cols(m, vector<bool>(n - 1));
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n - 1; ++i) {
            sorted_cols[j][i] = (table[i][j] <= table[i + 1][j]);
        }
    }
    
    // Для каждого столбца создаем массив префиксных сумм
    vector<vector<int>> prefix(m, vector<int>(n));
    for (int j = 0; j < m; ++j) {
        prefix[j][0] = 0;
        for (int i = 1; i < n; ++i) {
            prefix[j][i] = prefix[j][i - 1] + (sorted_cols[j][i - 1] ? 1 : 0);
        }
    }
    
    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        l--; r--; // Переводим в 0-индексацию
        
        bool found = false;
        for (int j = 0; j < m; ++j) {
            // Проверяем, что все пары между l и r-1 отсортированы
            int sum = prefix[j][r] - prefix[j][l];
            if (sum == r - l) {
                found = true;
                break;
            }
        }
        
        cout << (found ? "Yes" : "No") << '\n';
    }
    
    return 0;
}
*/