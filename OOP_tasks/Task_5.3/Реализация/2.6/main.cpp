#include <iostream>
#include <list>

// Функция для вычисления значения выражения
double calculateExpression(int n, const std::list<double>& numbers) {
    double result = 0.0;

    auto iter1 = numbers.begin();
    auto iter2 = numbers.end();
    iter2--;

    for (int i = 0; i < n - 1 ; i++) {
        result += *iter1;
        iter1++;
        result += *iter1;
        result += *iter2 * (n-i);
        iter2--;
    }

    return result;
}

int main() {
    int n;
    std::cout << "Input list length: ";
    std::cin >> n;

    std::list<double> numbers;
    std::cout << "Input "<< n << " numbers:\n";
    for (int i = 0; i < n; ++i) {
        double num;
        std::cin >> num;
        numbers.push_back(num);
    }

    // Вычисляем значение выражения
    double result = calculateExpression(n, numbers);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
