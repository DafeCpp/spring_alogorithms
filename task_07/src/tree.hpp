#include <vector>

class Tree {
 public:
  int add(int val);
  int pop();

 private:
  std::vector<int> data;
  int sift_up(int item);
  int sift_down(int item);
};