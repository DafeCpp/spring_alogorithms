#include <iostream>

#include "stack.hpp"

int main() {
  Stack stack;
  stack.push(2);
  stack.push(1);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  stack.push(7);

  stack.display();
  std::cout << "\n";

  stack.pop();
  stack.display();
  std::cout << "\n";

  int a = stack.peek();
  std::cout << a << "\n";

  int b = stack.min();
  std::cout << "minimal element: " << b;
  return 0;
}
