# Операции вставки и удаления в красно-чёрном дереве

## 1. Общая схема

Как и в AVL, операции удобно понимать в два этапа:

1. обычная операция `BST`;
2. ремонт цветовых инвариантов.

Это очень важная мысль:

сама логика поиска по ключу никуда не исчезает. Red-black дерево не
придумывает новый способ искать элементы — оно просто чинит структуру после
изменения.

---

## 2. Вставка: первый шаг

Сначала новая вершина вставляется как в обычный `BST`:

- по ключу ищем место;
- создаём вершину в нужной пустой позиции.

До этого момента логика полностью совпадает с обычным деревом поиска.

---

## 3. Почему новую вершину делают красной

Это один из самых важных conceptual points.

Если вставить новую вершину чёрной, мы можем сразу сломать инвариант равенства
чёрных высот путей.

Если вставить её красной:

- число чёрных вершин на путях пока не меняется;
- значит структура нарушается мягче.

Поэтому красная вставка — это способ минимизировать первоначальный ущерб.

---

## 4. Что может сломаться после вставки

Главная потенциальная проблема:

```text
красная вершина получила красного родителя
```

То есть нарушился инвариант “у красной вершины не может быть красного ребёнка”.

Очень полезно видеть вставку именно так:

- чёрная высота почти не пострадала;
- основная локальная беда — конфликт двух красных подряд.

---

## 5. Почему анализируют дядю

Когда новая красная вершина конфликтует с красным родителем, важно посмотреть на
брата родителя — так называемого **дядю**.

От его цвета зависит, что удобнее:

- просто перекрасить локальную конфигурацию;
- или выполнять вращение.

То есть дядя показывает, “плотно” ли уже заполнен этот уровень дерева по цвету.

---

## 6. Два больших сценария вставки

### Дядя красный

Тогда конфликт можно сначала лечить перекрашиванием:

- родителя и дядю делаем чёрными;
- дедушку — красным.

Проблема может подняться выше.

### Дядя чёрный

Тогда уже недостаточно просто перекрасить, и обычно нужны вращения.

Именно здесь появляются конфигурации типа:

- левый-левый;
- левый-правый;
- правый-правый;
- правый-левый.

То есть идея похожа на AVL: надо понять форму локального перекоса.

---

## 7. Что реально делают вставочные вращения

Вращение после вставки решает не абстрактную задачу “улучшить дерево”, а очень
конкретную:

- убрать две красные вершины подряд;
- при этом не нарушить чёрную высоту больше, чем нужно.

Перекрашивание и вращение вместе образуют локальный ремонт цветовой геометрии.

---

## 8. Удаление: почему оно существенно тяжелее

Удаление в red-black дереве психологически сложнее вставки, потому что:

- удаляемая вершина может быть чёрной;
- тогда некоторые пути теряют одну чёрную вершину;
- возникает дисбаланс именно по чёрной высоте.

Это уже не “локальный конфликт двух красных”, а более тонкая проблема:

> где-то в дереве как будто не хватает одного чёрного уровня.

---

## 9. Идея double black

Во многих объяснениях используют понятие:

```text
double black
```

Это не буквальный третий цвет, а удобная модель:

- после удаления чёрной вершины некоторая позиция как будто получила “лишнюю
  нехватку чёрного”.

Дальше алгоритм пытается:

- поднять эту проблему вверх;
- перераспределить её;
- или погасить локально через вращения и перекрашивания.

Это очень полезная интуиция для удаления.

---

## 10. Почему анализируют брата при удалении

После удаления внимание почти всегда сосредоточено вокруг:

- текущей проблемной позиции;
- её брата;
- родителя;
- и детей брата.

Почему брат так важен:

- именно его цвет и структура его поддерева показывают, можно ли компенсировать
  нехватку чёрного локально;
- или проблему придётся поднимать выше.

То есть брат — это “источник резервной структурной массы” для починки.

---

## 11. Основные сценарии удаления

На уровне идей полезно помнить такие случаи:

### Брат красный

Тогда конфигурация неудобна, но её часто можно быстро преобразовать вращением к
случаю, где брат чёрный.

### Брат чёрный и его дети чёрные

Тогда часто делают перекрашивание и поднимают проблему выше к родителю.

### Брат чёрный и у него есть красный ребёнок

Тогда можно выполнить локальные вращения и перекраску, чтобы погасить дефицит
чёрного на месте.

Это уже не список “магических правил”, а логика перераспределения чёрной высоты.

---

## 12. Почему все исправления всё равно укладываются в `O(log n)`

Потому что:

- мы движемся вдоль одного пути к корню;
- на каждом шаге выполняем только константное число локальных действий;
- высота дерева логарифмическая.

Значит и вставка, и удаление работают за:

```text
O(log n)
```

в худшем случае.

---

## 13. Реализация на C++

Ниже — учебная реализация вставки и `FixInsert` для red-black дерева.

```cpp
enum class Color {
  Red,
  Black
};

struct Node {
  int key;
  Color color = Color::Red;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
};

void RotateLeft(Node*& root, Node* x);
void RotateRight(Node*& root, Node* y);

void FixInsert(Node*& root, Node* z) {
  while (z->parent != nullptr && z->parent->color == Color::Red) {
    Node* parent = z->parent;
    Node* grand = parent->parent;

    if (parent == grand->left) {
      Node* uncle = grand->right;

      if (uncle != nullptr && uncle->color == Color::Red) {
        parent->color = Color::Black;
        uncle->color = Color::Black;
        grand->color = Color::Red;
        z = grand;
      } else {
        if (z == parent->right) {
          z = parent;
          RotateLeft(root, z);
          parent = z->parent;
          grand = parent->parent;
        }
        parent->color = Color::Black;
        grand->color = Color::Red;
        RotateRight(root, grand);
      }
    } else {
      Node* uncle = grand->left;

      if (uncle != nullptr && uncle->color == Color::Red) {
        parent->color = Color::Black;
        uncle->color = Color::Black;
        grand->color = Color::Red;
        z = grand;
      } else {
        if (z == parent->left) {
          z = parent;
          RotateRight(root, z);
          parent = z->parent;
          grand = parent->parent;
        }
        parent->color = Color::Black;
        grand->color = Color::Red;
        RotateLeft(root, grand);
      }
    }
  }
  root->color = Color::Black;
}

void Insert(Node*& root, int key) {
  Node* z = new Node{key};
  Node* y = nullptr;
  Node* x = root;

  while (x != nullptr) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  z->parent = y;
  if (y == nullptr) {
    root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }

  FixInsert(root, z);
}
```

Для полноты картины ниже — учебный каркас удаления.

```cpp
Color GetColor(Node* v) {
  return v == nullptr ? Color::Black : v->color;
}

Node* TreeMinimum(Node* root) {
  while (root->left != nullptr) {
    root = root->left;
  }
  return root;
}

void Transplant(Node*& root, Node* u, Node* v) {
  if (u->parent == nullptr) {
    root = v;
  } else if (u == u->parent->left) {
    u->parent->left = v;
  } else {
    u->parent->right = v;
  }
  if (v != nullptr) {
    v->parent = u->parent;
  }
}

void FixErase(Node*& root, Node* x, Node* parent) {
  while (x != root && GetColor(x) == Color::Black) {
    if (x == (parent != nullptr ? parent->left : nullptr)) {
      Node* w = parent->right;

      if (GetColor(w) == Color::Red) {
        w->color = Color::Black;
        parent->color = Color::Red;
        RotateLeft(root, parent);
        w = parent->right;
      }

      if (GetColor(w != nullptr ? w->left : nullptr) == Color::Black &&
          GetColor(w != nullptr ? w->right : nullptr) == Color::Black) {
        if (w != nullptr) {
          w->color = Color::Red;
        }
        x = parent;
        parent = x->parent;
      } else {
        if (GetColor(w != nullptr ? w->right : nullptr) == Color::Black) {
          if (w != nullptr && w->left != nullptr) {
            w->left->color = Color::Black;
          }
          if (w != nullptr) {
            w->color = Color::Red;
            RotateRight(root, w);
          }
          w = parent->right;
        }

        if (w != nullptr) {
          w->color = parent->color;
        }
        parent->color = Color::Black;
        if (w != nullptr && w->right != nullptr) {
          w->right->color = Color::Black;
        }
        RotateLeft(root, parent);
        x = root;
      }
    } else {
      Node* w = parent->left;

      if (GetColor(w) == Color::Red) {
        w->color = Color::Black;
        parent->color = Color::Red;
        RotateRight(root, parent);
        w = parent->left;
      }

      if (GetColor(w != nullptr ? w->right : nullptr) == Color::Black &&
          GetColor(w != nullptr ? w->left : nullptr) == Color::Black) {
        if (w != nullptr) {
          w->color = Color::Red;
        }
        x = parent;
        parent = x->parent;
      } else {
        if (GetColor(w != nullptr ? w->left : nullptr) == Color::Black) {
          if (w != nullptr && w->right != nullptr) {
            w->right->color = Color::Black;
          }
          if (w != nullptr) {
            w->color = Color::Red;
            RotateLeft(root, w);
          }
          w = parent->left;
        }

        if (w != nullptr) {
          w->color = parent->color;
        }
        parent->color = Color::Black;
        if (w != nullptr && w->left != nullptr) {
          w->left->color = Color::Black;
        }
        RotateRight(root, parent);
        x = root;
      }
    }
  }

  if (x != nullptr) {
    x->color = Color::Black;
  }
}

void Erase(Node*& root, Node* z) {
  Node* y = z;
  Color original_color = y->color;
  Node* x = nullptr;
  Node* x_parent = nullptr;

  if (z->left == nullptr) {
    x = z->right;
    x_parent = z->parent;
    Transplant(root, z, z->right);
  } else if (z->right == nullptr) {
    x = z->left;
    x_parent = z->parent;
    Transplant(root, z, z->left);
  } else {
    y = TreeMinimum(z->right);
    original_color = y->color;
    x = y->right;

    if (y->parent == z) {
      x_parent = y;
      if (x != nullptr) {
        x->parent = y;
      }
    } else {
      x_parent = y->parent;
      Transplant(root, y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }

    Transplant(root, z, y);
    y->left = z->left;
    y->left->parent = y;
    y->color = z->color;
  }

  delete z;

  if (original_color == Color::Black) {
    FixErase(root, x, x_parent);
  }
}
```

Этот код уже заметно тяжелее вставки, и именно поэтому удаление в red-black
дереве почти всегда считается самой сложной частью структуры.

---

## 14. Сравнение вставки и удаления

| Операция | Главная проблема | Типичный характер починки |
|---|---|---|
| Вставка | две красные подряд | перекраска + иногда вращение |
| Удаление | потеря чёрной высоты | перекраска, вращение, возможный подъём проблемы вверх |

Это очень хорошая таблица для внутреннего понимания:

- вставка в red-black локально проще;
- удаление концептуально тяжелее.

---

## 15. Почему red-black считают практичным, несмотря на сложность

Потому что за всей кажущейся тяжестью случаев стоит очень устойчивая идея:

- форма дерева контролируется;
- высота гарантированно логарифмическая;
- ремонт происходит локально;
- структура хорошо подходит для общего назначение ordered containers.

То есть это не “сложность ради сложности”, а сложность ради сильной и полезной
гарантии.

---

## 16. Что важно запомнить

Вставку и удаление в red-black дереве нужно понимать через две большие цели:

1. не допускать двух красных подряд;
2. сохранять одинаковую чёрную высоту путей.

Все частные случаи — это просто технические способы выполнить именно эти две
задачи.

Если смотреть на тему именно так, red-black дерево перестаёт быть набором
магических кейсов и превращается в очень логичную структуру с сильной
геометрией инвариантов.
