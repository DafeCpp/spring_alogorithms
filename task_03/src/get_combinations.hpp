#include <string>
#include <vector>

using namespace std;

const vector<string> v_s{"abc", "def",  "ghi", "jkl",
                         "mno", "pqrs", "tuv", "wxyz"};
constexpr int shift = 2;

void get_small_combination(vector<int> nums, int i, string s,
                           vector<string> &result) {
  if (i == nums.size()) {
    result.push_back(s);
    return;
  }

  string s_new;
  for (char c : v_s[nums[i] - shift]) {
    s_new = s + c;
    get_small_combination(nums, i + 1, s_new, result);
  }
}

vector<string> get_combinations(string digits) {
  vector<int> nums;
  for (char c : digits) {
    if (c >= '2' && c <= '9') {
      nums.push_back(c - '0');
    }
  }
  vector<string> result;

  if (nums.empty()) return result;

  string s;
  int i = 0;

  get_small_combination(nums, i, s, result);
  return result;
}