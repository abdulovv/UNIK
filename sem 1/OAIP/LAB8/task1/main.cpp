#include <iostream>
#include <string>
#include "regularCustomer.h"

using namespace std;

int currentLength = 3;

void menu() {
    cout << "1. Просмотра содержимого динамического массива структур" << endl;
    cout << "2. Дополнения уже существующего массива структур новыми структурами " << endl;
    cout << "3. Функцию поиска и вывода на экран структур с заданным значением элемента. " << endl;
    cout << "4. Функции удаления элемента массива структур с заданным значением элемента." << endl;
    cout << "5. Функции изменения элемента массива структур с заданным значением элемента." << endl;
    cout << "6. Функцию упорядочения массива структур по одному из полей (элементов)." << endl;
    cout << "7. Вывести всех покупателей, имеющих 5 % -ную скидку" << endl;
    cout << "8. Выход " << endl;
    cout << "Ввод:";
}


int main() {
    setlocale(0, "");

    int cmd;
    auto customers = new customer[currentLength];

    startArray(customers);
    do {
        menu();
        while (!(cin >> cmd) && (cin.peek() != '\n')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введите снова.";
        }

        switch (cmd) {
        case 1:
            printAllCustomers(customers, currentLength);
            break;
        case 2:
            customers = addNewClient(customers, &currentLength);
            break;
        case 3: 
        {
            auto list = new customer;
            bool found = false;
            int size = 0;
            list = search(customers, &found, &size, &currentLength);
            if (found) {
                cout << "Результат поиска:" << endl;
                printAllCustomers(list, size);
            }
            else {
                cout << "Клиентов не найдено." << endl;
            }
        }
              break;
        case 4: 
        {
            customers = remove(customers, &currentLength);
            printAllCustomers(customers, currentLength);
        }
              break;

        case 5:
            customers = change(customers, &currentLength);
            break;

        case 6:
            customers = sort(customers, &currentLength);
            break;
        case 7:
            printPercent5(customers, &currentLength);
            break;
        case 8:
            break;
        default:
            cout << "Введите снова." << endl;
            break;
        }
    } while (cmd != 8);
}
