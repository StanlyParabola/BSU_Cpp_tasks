#include "Rational.h"
#include <iostream>
#include <stdexcept>

// Вспомогательная функция для вычисления НОД
int Rational::gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Приведение дроби к несократимому виду
void Rational::reduce() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Конструкторы
Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
    if (denom == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    reduce();
}

Rational::Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator) {}

Rational::Rational(Rational&& other) noexcept : numerator(other.numerator), denominator(other.denominator) {
    other.numerator = 0;
    other.denominator = 1;
}

// Деструктор
Rational::~Rational() {}

// Операторы присваивания
Rational& Rational::operator=(const Rational& other) {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

Rational& Rational::operator=(Rational&& other) noexcept {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
        other.numerator = 0;
        other.denominator = 1;
    }
    return *this;
}

// Перегрузка арифметических операций
Rational Rational::operator+(const Rational& other) const {
    return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

Rational Rational::operator-(const Rational& other) const {
    return Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(numerator * other.numerator, denominator * other.denominator);
}

Rational Rational::operator/(const Rational& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Cannot divide by zero.");
    }
    return Rational(numerator * other.denominator, denominator * other.numerator);
}

// Перегрузка операций сравнения
bool Rational::operator==(const Rational& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}

bool Rational::operator<(const Rational& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Rational::operator<=(const Rational& other) const {
    return *this < other || *this == other;
}

bool Rational::operator>(const Rational& other) const {
    return !(*this <= other);
}

bool Rational::operator>=(const Rational& other) const {
    return !(*this < other);
}

// Перегрузка операций ввода/вывода
std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.numerator << "/" << r.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
    char slash;
    is >> r.numerator >> slash >> r.denominator;
    if (r.denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    r.reduce();
    return is;
}

// Прочие методы
void Rational::set(int num, int denom) {
    if (denom == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    numerator = num;
    denominator = denom;
    reduce();
}

void Rational::get(int &num, int &denom) const {
    num = numerator;
    denom = denominator;
}
