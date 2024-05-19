#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <ctime>

class Vector {
private:
    int* elements; // Указатель на массив элементов
    int size;      // Размер вектора

public:
    // Конструкторы и деструктор
    Vector();
    Vector(int size);
    ~Vector();

    // Конструктор копирования
    Vector(const Vector& other);

    // Оператор копирования
    Vector& operator=(const Vector& other);

    // Конструктор перемещения
    Vector(Vector&& other) noexcept;

    // Оператор перемещения
    Vector& operator=(Vector&& other) noexcept;

    // Методы
    void resize(int newSize);
    int getSize() const;
    void fillRandom();

    // Перегрузка операторов индексирования
    int& operator[](int index);
    const int& operator[](int index) const;

    // Перегрузка операторов ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);
};

#endif
