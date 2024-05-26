#include <iostream>
#include "Rational.h"

int main() {
    Rational r1, r2;
    std::cout << "input first rational (m/n): ";
    std::cin >> r1;
    std::cout << "input second rational (m/n): ";
    std::cin >> r2;

    std::cout << "first rational: " << r1 << std::endl;
    std::cout << "second rational: " << r2 << std::endl;

    Rational sum = r1 + r2;
    Rational difference = r1 - r2;
    Rational product = r1 * r2;
    Rational quotient = r1 / r2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Subtract: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Division: " << quotient << std::endl;

    if (r1 == r2) {
        std::cout << "Rational are equal" << std::endl;
    } else {
        std::cout << "Rational are not equal" << std::endl;
    }

    return 0;
}
