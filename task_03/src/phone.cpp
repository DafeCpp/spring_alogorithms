#include <vector>
#include <string>
#include <unordered_map>
#include "phone.hpp"

void dfs(int pos,
    const std::string& digits,
    const std::unordered_map<char, std::string>& phone,
    std::string& current,
    std::vector<std::string>& result){

        if (pos == digits.size()){
            result.push_back(current);
            return;
        }
        
        for(char c: phone.at(digits[pos])){
            current.push_back(c);
            dfs(pos+1, digits, phone, current,result);
            current.pop_back();
        }
    }



std::vector<std::string> phone(std::string& digits){

    std::unordered_map<char, std::string> phone = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    std::vector<std::string> result;
    std::string current;

    dfs(0, digits, phone, current, result);

    return result;
}