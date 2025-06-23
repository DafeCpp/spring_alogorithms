#include "solution.hpp"

#include <stack>
#include <vector>

std::vector<int> DaysToWarming(std::vector<float> temps) {
  std::stack<float> temp_steps;
  std::stack<float> temp_steps_days;

  std::vector<int> res(temps.size());

  for (int day = temps.size() - 1; day >= 0; --day) {
    while (!temp_steps.empty() && temp_steps.top() <= temps[day]) {
      temp_steps.pop();
      temp_steps_days.pop();
    }

    if (!temp_steps.empty()) {
      //
      // 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8
      //   | c | 1 | 2 | 3 | + |
      //
      // 6 - 2 = 4 = 3 + current
      res[day] = temp_steps_days.top() - day;
    } else {
      res[day] = 0;  // there won't be any warmer days
    }

    temp_steps.push(temps[day]);
    temp_steps_days.push(day);
  }

  return res;
}
