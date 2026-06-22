#ifndef TASK14_HPP
#define TASK14_HPP

class TableChecker {
 private:
  int n, m;
  int** good;

 public:
  TableChecker(int rows, int cols, int** table);
  ~TableChecker();
  bool check(int l, int r);
};

#endif