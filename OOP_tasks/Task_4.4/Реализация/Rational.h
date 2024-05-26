#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
private:
    int numerator;
    int denominator;
    void reduce(); // Приведение к несократимому виду
    int gcd(int a, int b); // Наибольший общий делитель

public:
    // Конструкторы
    Rational();
    Rational(int num, int denom);
    Rational(const Rational& other); // Конструктор копирования
    Rational(Rational&& other) noexcept; // Конструктор перемещения

    // Деструктор
    ~Rational();

    // Правило пяти
    Rational& operator=(const Rational& other);
    Rational& operator=(Rational&& other) noexcept;

    // Перегрузка операций
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator>=(const Rational& other) const;

    // Перегрузка операций ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);

    // Прочие методы
    void set(int num, int denom);
    void get(int &num, int &denom) const;
};

#endif // RATIONAL_H
