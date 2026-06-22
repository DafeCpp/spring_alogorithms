#include <vector>
#include <string>

std::vector<std::string> GetCombinations(const std::string& digits) {
    if (digits.empty()) {
        return {};
    }
    std::string keyboard[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    std::vector<std::string> result = {""};
    for (auto i = 0; i < digits.size(); ++i) {
        std::string letters = keyboard[digits[i] - '2'];
        std::vector<std::string> new_result;
        for (auto prefix : result) {
            for (char c : letters) {
                new_result.push_back(prefix + c);
            }
        }
        result = new_result;
    }

    return result;
}
