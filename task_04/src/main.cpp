#include <iostream>
#include "stack.hpp"
//пока не мой, нужно было разобраться с технической частью 
int main() {
    std::cout << "=== Тестируем обычный Stack ===" << std::endl;
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);

    std::cout << "Достали из Stack: " << s.Pop() << " (ожидаем 30)" << std::endl;
    std::cout << "Достали из Stack: " << s.Pop() << " (ожидаем 20)" << std::endl;

    std::cout << "\n=== Тестируем MinStack ===" << std::endl;
    MinStack ms;
    
    std::cout << "Пушим 5..." << std::endl;
    ms.Push(5);
    std::cout << "Текущий минимум: " << ms.GetMin() << " (ожидаем 5)" << std::endl;

    std::cout << "Пушим 3..." << std::endl;
    ms.Push(3);
    std::cout << "Текущий минимум: " << ms.GetMin() << " (ожидаем 3)" << std::endl;

    std::cout << "Пушим 7..." << std::endl;
    ms.Push(7);
    std::cout << "Текущий минимум: " << ms.GetMin() << " (ожидаем 3)" << std::endl;

    std::cout << "\nУдаляем элемент с вершины (это 7): " << ms.Pop() << std::endl;
    std::cout << "Текущий минимум: " << ms.GetMin() << " (ожидаем 3)" << std::endl;

    std::cout << "Удаляем элемент с вершины (это 3): " << ms.Pop() << std::endl;
    std::cout << "Текущий минимум: " << ms.GetMin() << " (ожидаем 5) -> откатился назад!" << std::endl;

    return 0;
}