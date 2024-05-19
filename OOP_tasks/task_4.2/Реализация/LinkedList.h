#include <iostream>

template<typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    ListNode() : next(nullptr) {}
    ListNode(T val) : data(val), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    ListNode<T>* head;

public:
    LinkedList() : head(nullptr) {}

    // Конструктор копирования
    LinkedList(const LinkedList& other) {
        copy(other);
    }

    // Оператор присваивания
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            copy(other);
        }
        return *this;
    }

    // Конструктор перемещения
    LinkedList(LinkedList&& other) noexcept {
        head = other.head;
        other.head = nullptr;
    }

    // Оператор перемещения
    LinkedList& operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            other.head = nullptr;
        }
        return *this;
    }

    ~LinkedList() {
        clear();
    }

    // Метод инициализации первого элемента
    void initialize(T val) {
        if (!head) {
            head = new ListNode<T>(val);
        }
    }

    ListNode<T>* getHead() const {
        return head;
    }

    // Метод добавления нового элемента в конец списка
    void add(T val) {
        if (!head) {
            initialize(val);
            return;
        }

        ListNode<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new ListNode<T>(val);
    }

    // Метод удаления элемента по значению
    void remove(T val) {
        ListNode<T>* current = head;
        ListNode<T>* prev = nullptr;

        while (current) {
            if (current->data == val) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Метод поиска элемента по значению
    ListNode<T>* find(T val) {
        ListNode<T>* current = head;
        while (current) {
            if (current->data == val) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Метод вывода элементов списка на экран
    void display() {
        ListNode<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Метод удаления списка
    void clear() {
        ListNode<T>* current = head;
        while (current) {
            ListNode<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    int countOccurrences(T val) {
        int count = 0;
        ListNode<T>* current = head;
        while (current) {
            if (current->data == val) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
    ListNode<T>* getNth(int n) {
        if (n < 0) {
            return nullptr;
        }
        ListNode<T>* current = head;
        for (int i = 0; i < n && current; ++i) {
            current = current->next;
        }
        return current;
    }
    void findSymbolsTwice() {
        bool found[256] = {false}; // Массив для отслеживания вхождений символов
        ListNode<T>* current = head;
        while (current) {
            if (countOccurrences(current->data) == 2 && !found[current->data]) {
                std::cout << current->data << " ";
                found[current->data] = true;
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    LinkedList<T> createListFromSymbolsTwice() {
        LinkedList<T> newList;
        bool found[256] = {false}; // Массив для отслеживания вхождений символов
        ListNode<T>* current = head;
        while (current) {
            if (countOccurrences(current->data) == 2 && !found[current->data]) {
                newList.add(current->data);
                found[current->data] = true;
            }
            current = current->next;
        }
        return newList;
    }


private:
    // Вспомогательная функция для копирования списка
    void copy(const LinkedList& other) {
        if (!other.head) {
            head = nullptr;
            return;
        }
        head = new ListNode<T>(other.head->data);
        ListNode<T>* current = head;
        ListNode<T>* otherCurrent = other.head->next;
        while (otherCurrent) {
            current->next = new ListNode<T>(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }
};
