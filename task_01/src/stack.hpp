#include <vector>

class Stack{
public:
  Stack() {}

  int Pop() {
    int res = data_.back();
    data_.pop_back();
    return res;
  };

  void Push(int value) {data_.push_back(value);};

private:
  std::vector<int> data_;
};