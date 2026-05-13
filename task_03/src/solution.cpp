#include "solution.hpp"

const std::vector<std::string> convert = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void AddCombination(int index, const std::string& s, std::vector<std::string>& add, std::string current) {
    if (index == s.size()) {
        add.push_back(current);
        return;
    }
    for (char c : convert[s[index] - '2']) {
        std::string new_s = current + c;
        AddCombination(index + 1, s, add, new_s);
    }
}

std::vector<std::string> ButtonPhone(std::string s) {
    std::vector<std::string> result;
    AddCombination(0, s, result, "");
    return result;
}