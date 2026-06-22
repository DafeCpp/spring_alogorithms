#include "phone_algorithm.hpp"

#include <unordered_map>
#include <vector>

const std::unordered_map<char, std::string> number_to_symbols{
    {'1', ""},    {'2', "abc"},  {'3', "def"}, {'4', "ghi"},  {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}, {'0', ""}};

void DFS(const std::string& str, std::size_t pos, const std::string& cur,
         std::vector<std::string>& ans) {
  if (pos == str.size()) {
    ans.push_back(cur);
    return;
  }
  for (auto ch : number_to_symbols.at(str[pos])) {
    DFS(str, pos + 1, cur + ch, ans);
  }
}

std::vector<std::string> PhoneAlgorithm(const std::string& number) {
  std::vector<std::string> ans;
  if (!number.empty()) DFS(number, 0, "", ans);
  return ans;
}