#include <iostream>
#include <vector>

int main() {
    int n, summ;
    std::cin >> summ >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        int cur_summ = arr[i] + arr[j];
        if (cur_summ == summ) {
            std::cout << arr[i] << " " << arr[j];
            return 0;
        }
        if (cur_summ < summ) {
            i++;
        } else {
            j--;
        }
    }
    std::cout << -1;
}
