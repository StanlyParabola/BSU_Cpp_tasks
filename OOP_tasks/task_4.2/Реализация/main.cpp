#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

    int n;
    LinkedList<char> list;

    cout<<"input list length:";
    cin>>n;
    cout<<"fill list:\n";
    for(int i = 0; i < n; i ++){
        char tmp;
        cin>>tmp;
        list.add(tmp);
    }

    // Формирование нового списка из символов, встречающихся в списке ровно два раза
    LinkedList<char> newList = list.createListFromSymbolsTwice();

    // Вывод нового списка на экран
    cout << "New list of elements appearing twice in the initial list:\n";
    newList.display();

    return 0;
}

