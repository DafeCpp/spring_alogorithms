# **Метод цепочек (открытое хеширование).**
Хэш-таблицы представляют собой эффективную структуру данных, позволяющую осуществлять хранение и поиск информации. Однако, при использовании хэш-таблиц возможно возникновение ситуаций, когда два или более ключей отображаются в одну и ту же ячейку таблицы, что называется коллизией. Для разрешения подобных проблем существует ряд методов, среди которых особое место занимает метод цепочек.

Идея метода цепочек заключается в том, что в случае если хеш-функция выделяет один индекс сразу двум элементам, то храниться они будут в одном и том же индексе, но уже с помощью двусвязного списка.
> Если ```j``` — ячейка для нескольких элементов, то она содержит указатель на первый элемент списка. Если же ```j``` пуста, то она содержит ```NULL```.
![](https://lh3.googleusercontent.com/Yd-JtIVQlDI9U9b7N3miEc_McdYR2nTT2ruVNPA3cQ0dJ-Rn8OPmkMHjrQGNqUh39hoBV8En3-pGpmvuLYA1OQ1pcCc--EaOQXmDSdDrKBsNYNoBYh5jzSIxY6kRLSMnlOSCrIWr)
***
**Псевдокод операций**
```python
class HashTable:
    size: int
    table[]: list
    def Insert(value):
        index = hash(value)
        table[index].push_front(value)
        
    def Search(value):
        index = hash(value)
        for elem in table[index]:
            if elem == value:
                return True
        return False
        
    def Remove(value):
        index = hash(value)
        for elem in table[index]:
            if elem == value:
                previous_elem = elem->prev
                next_elem = elem->next
                previous_elem->next = next_elem
       
    
