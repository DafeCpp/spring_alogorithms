#include <forward_list>
#include <optional>
#include <vector>

class HashTable {
 public:
  HashTable(size_t size = 10);

  void Insert(int key, int value);  // вставка пары ключ-значение
  std::optional<int> Get(int key);  // получение значения по ключу
  void Remove(int key);             // удаление по ключу
  bool Contains(int key);  // проверка наличия ключа

 private:
  struct Node {
    int key;
    int value;
  };

  std::vector<std::forward_list<Node>> data;
};
