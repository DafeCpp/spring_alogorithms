#include <string>

int FindSubSeq(const std::string& str, const std::string& sequence){
int n = str.size();
    int m = sequence.size();
    if (m == 0) return 1;
    if (m > n) return -1;
    int target[26] = {0};
    for (int i = 0; i < m; ++i) {
        target[sequence[i] - 'a']++;
    }
    int window[26] = {0};
    for (int i = 0; i < m; ++i) {
        window[str[i] - 'a']++;
    }
    bool eq = true;
    for (int i = 0; i < 26; ++i) {
        if (target[i] != window[i]) {
            eq = false;
            break;
        }
    }
    if (eq) return 1;

    for (int i = m; i < n; ++i) {
        window[str[i] - 'a']++;
        window[str[i - m] - 'a']--;

        eq = true;
        for (int j = 0; j < 26; ++j) {
            if (target[j] != window[j]) {
                eq = false;
                break;
            }
        }
        if (eq) {
            return i - m + 2;
        }
    }
    return -1;
}