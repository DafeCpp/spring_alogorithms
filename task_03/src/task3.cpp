#include <memory>
#include <string>
#include <vector>

class KeyboardTree {
 private:
  struct Node {
    char letter;
    std::vector<std::unique_ptr<Node>> children;
    Node(char ch) : letter(ch) {}
  };

  std::unique_ptr<Node> root;
  const std::vector<std::string> Keyboard;

  void build_subTree(Node* current_node, const std::string& digits,
                     size_t index) {
    if (index == digits.length()) {
      return;
    }

    int digit = digits[index] - '0';
    const std::string& letters = Keyboard[digit];

    for (char letter : letters) {
      auto child = std::make_unique<Node>(letter);

      Node* child_ptr = child.get();
      current_node->children.push_back(std::move(child));
      build_subTree(child_ptr, digits, index + 1);
    }
  }

  void DFS(Node* current_node, std::string& current_str,
           std::vector<std::string>& result) {
    if (current_node->letter != '\0') {
      current_str.push_back(current_node->letter);
    }

    if (current_node->children.empty()) {
      if (!current_str.empty()) {
        result.push_back(current_str);
      }
    } else {
      for (const auto& child : current_node->children) {
        DFS(child.get(), current_str, result);
      }
    }

    if (current_node->letter != '\0') {
      current_str.pop_back();
    }
  }

 public:
  KeyboardTree()
      : Keyboard({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",
                  "wxyz"}) {
    root = std::make_unique<Node>('\0');
  }

  void build(const std::string& digits) {
    if (digits.empty()) return;
    build_subTree(root.get(), digits, 0);
  }

  std::vector<std::string> getCombinations() {
    std::vector<std::string> result;
    std::string current_str = "";
    DFS(root.get(), current_str, result);
    return result;
  }
};

std::vector<std::string> runKeyboardTree(const std::string& digits) {
  if (digits.empty()) {
    return {""};
  }

  KeyboardTree tree;
  tree.build(digits);

  std::vector<std::string> result = tree.getCombinations();
  return result;
}