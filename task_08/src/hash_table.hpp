#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

struct HashTableError : std::runtime_error {
  using std::runtime_error::runtime_error;
};
enum class Condition { Empty, Full, Cleared };

struct HashTable {
 public:
  HashTable();
  HashTable(size_t size);
  HashTable(const std::vector<std::pair<std::string, int>>& input);
  void Add(const std::string& new_key, int new_value);
  void Del(const std::string& del_key);
  int Get(const std::string& key);

 private:
  struct Element {
   public:
    Condition condition = Condition::Empty;
    std::string key;
    int value;
  };
  std::vector<Element> array;
  std::hash<std::string> base_hasher;
  int full_elements = 0;
  void UpdateArray();
  int FindIndex(const std::string& key);  // находит, если существует
                                          // если нет такого, возвращает -1
  int FirstHashFunc(const std::string& num);
  int SecondHashFunc(const std::string& num);
  int HashFunc(const std::string& num, int iteration);
};