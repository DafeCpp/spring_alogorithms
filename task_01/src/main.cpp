#include <iostream>

#include "FindSum.hpp"


#include <vector>

using namespace std;

int main() {
    int target_sum;
    cin >> target_sum;

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = find_pair_with_sum(target_sum, arr);

    // Выводим ответ
    if (result.first == -1 && result.second == -1) {
        cout << -1 << endl;
    } else {
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}