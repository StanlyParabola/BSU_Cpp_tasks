
#ifndef INC_2LINKEDLIST_BILINKEDLIST_H
#define INC_2LINKEDLIST_BILINKEDLIST_H
#endif //INC_2LINKEDLIST_BILINKEDLIST_H

template <typename T>
class BiLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

    void clear();

public:
    // Конструкторы
    BiLinkedList() : head(nullptr), tail(nullptr) {}
    BiLinkedList(const T& value);
    ~BiLinkedList();

    // Правило пяти
    BiLinkedList(const BiLinkedList& other);
    BiLinkedList& operator=(const BiLinkedList& other);
    BiLinkedList(BiLinkedList&& other) noexcept;
    BiLinkedList& operator=(BiLinkedList&& other) noexcept;
    T getElementAt(int index);

    // Методы
    void initFirstElement(const T& value);
    void append(const T& value);
    void remove(const T& value);
    Node* find(const T& value);
    void print() const;
    void clearList();
};

// Конструктор с параметром
template <typename T>
BiLinkedList<T>::BiLinkedList(const T& value) {
    head = new Node(value);
    tail = head;
}

// Деструктор
template <typename T>
BiLinkedList<T>::~BiLinkedList() {
    clear();
}

// Конструктор копирования
template <typename T>
BiLinkedList<T>::BiLinkedList(const BiLinkedList& other) : head(nullptr), tail(nullptr) {
    Node* current = other.head;
    while (current) {
        append(current->data);
        current = current->next;
    }
}

// Оператор присваивания копированием
template <typename T>
BiLinkedList<T>& BiLinkedList<T>::operator=(const BiLinkedList& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current) {
            append(current->data);
            current = current->next;
        }
    }
    return *this;
}

// Конструктор перемещения
template <typename T>
BiLinkedList<T>::BiLinkedList(BiLinkedList&& other) noexcept : head(other.head), tail(other.tail) {
    other.head = nullptr;
    other.tail = nullptr;
}

// Оператор присваивания перемещением
template <typename T>
BiLinkedList<T>& BiLinkedList<T>::operator=(BiLinkedList&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}

// Инициализация первого элемента
template <typename T>
void BiLinkedList<T>::initFirstElement(const T& value) {
    clear();
    head = new Node(value);
    tail = head;
}

// Добавление нового элемента
template <typename T>
void BiLinkedList<T>::append(const T& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Удаление элемента
template <typename T>
void BiLinkedList<T>::remove(const T& value) {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

// Поиск элемента
template <typename T>
typename BiLinkedList<T>::Node* BiLinkedList<T>::find(const T& value) {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Вывод элементов на экран
template <typename T>
void BiLinkedList<T>::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Очистка всего списка
template <typename T>
void BiLinkedList<T>::clearList() {
    clear();
}

// Вспомогательный метод для очистки списка
template <typename T>
void BiLinkedList<T>::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
}

template <typename T>
T BiLinkedList<T>::getElementAt(int index) {
    Node* current = head;
    int count = 0;

    while (current) {
        if (count == index) {
            return current->data;
        }
        current = current->next;
        count++;
    }

    throw std::out_of_range("Index out of range");
}