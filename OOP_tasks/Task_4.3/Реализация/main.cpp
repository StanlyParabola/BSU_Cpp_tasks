#include <iostream>
#include "BiLinkedList.h"  // Подключаем ранее созданный шаблон класса

using namespace std;

// Функция для вычисления выражения
double computeExpression(BiLinkedList<double>& list, int n) {
    double result = 0.0;

    for (int i = 0; i < n - 1; i++) {
        double x = list.getElementAt(i);  // Элемент x_i
        double x1 = list.getElementAt(i+1);  // Элемент x_(i+1) (если i=n, то это x_1)
        double xj = list.getElementAt(n - i - 1);  // Элемент x_(n-i+1)

        result += (x + x1 + (n - i) * xj);
    }

    return result;
}

// Основная программа
int main() {
    int n;
    cout << "Input list length: ";
    cin >> n;

    BiLinkedList<double> list;
    cout << "Input " << n << " real numbers" << endl;

    for (int i = 0; i < n; ++i) {
        double value;
        cin >> value;
        list.append(value);
    }

    double result = computeExpression(list, n);
    cout << "Result: " << result << endl;

    return 0;
}
