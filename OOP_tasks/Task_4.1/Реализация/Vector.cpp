#include "Vector.h"

// Конструкторы и деструктор
Vector::Vector() : elements(nullptr), size(0) {}

Vector::Vector(int size) : size(size) {
    elements = new int[size];
}

Vector::~Vector() {
    delete[] elements;
}

// Конструктор копирования
Vector::Vector(const Vector& other) : size(other.size) {
    elements = new int[size];
    for (int i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

// Оператор копирования
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] elements;
        size = other.size;
        elements = new int[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

// Конструктор перемещения
Vector::Vector(Vector&& other) noexcept : elements(other.elements), size(other.size) {
    other.elements = nullptr;
    other.size = 0;
}

// Оператор перемещения
Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] elements;
        elements = other.elements;
        size = other.size;
        other.elements = nullptr;
        other.size = 0;
    }
    return *this;
}

// Методы
void Vector::resize(int newSize) {
    delete[] elements;
    size = newSize;
    elements = new int[size];
}

int Vector::getSize() const {
    return size;
}

void Vector::fillRandom() {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        elements[i] = rand() % 100; // Заполнение случайными числами от 0 до 99
    }
}

// Перегрузка операторов индексирования
int& Vector::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

const int& Vector::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

// Перегрузка операторов ввода/вывода
std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "[";
    for (int i = 0; i < vec.size; ++i) {
        os << vec.elements[i];
        if (i < vec.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

std::istream& operator>>(std::istream& is, Vector& vec) {
    for (int i = 0; i < vec.size; ++i) {
        is >> vec.elements[i];
    }
    return is;
}
