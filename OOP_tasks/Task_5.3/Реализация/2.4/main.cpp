#include <iostream>
#include <forward_list>

// Функция для подсчета вхождений каждого символа в L1
int countOccurrences(const std::forward_list<char>& L1, char symbol) {
    int count = 0;
    for (char c : L1) {
        if (c == symbol) {
            count++;
        }
    }
    return count;
}

// Функция для проверки наличия символа в списке
bool contains(const std::forward_list<char>& L, char symbol) {
    for (char c : L) {
        if (c == symbol) {
            return true;
        }
    }
    return false;
}

// Функция для формирования списка символов L2
std::forward_list<char> generateL2(const std::forward_list<char>& L1) {
    std::forward_list<char> L2;

    // Подсчитываем вхождения каждого символа в L1 и формируем список L2
    for (char c : L1) {
        int occurrences = countOccurrences(L1, c);
        if (occurrences == 2) {
            // Добавляем символ в список L2 только если его встречается ровно два раза
            // и его еще нет в списке L2
            if (!contains(L2, c)) {
                L2.push_front(c);
            }
        }
    }

    // Реверсируем список L2 для сохранения порядка добавления символов
    L2.reverse();

    return L2;
}

int main() {
    // Пример списка символов L1
    std::forward_list<char> L1 = {'a', 'c', 'c', 'a', 'b', 'd', 'e', 'd', 'e', 'f'};

    // Формируем список символов L2
    std::forward_list<char> L2 = generateL2(L1);

    // Выводим список символов L2
    std::cout << "List L2 L2:\n";
    for (char c : L2) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}
