#include <iostream>
#include <string>
#include "regularCustomer.h"

using namespace std;

int currentLength = 3;

void menu() {
    cout << "1. ��������� ����������� ������������� ������� ��������" << endl;
    cout << "2. ���������� ��� ������������� ������� �������� ������ ����������� " << endl;
    cout << "3. ������� ������ � ������ �� ����� �������� � �������� ��������� ��������. " << endl;
    cout << "4. ������� �������� �������� ������� �������� � �������� ��������� ��������." << endl;
    cout << "5. ������� ��������� �������� ������� �������� � �������� ��������� ��������." << endl;
    cout << "6. ������� ������������ ������� �������� �� ������ �� ����� (���������)." << endl;
    cout << "7. ������� ���� �����������, ������� 5 % -��� ������" << endl;
    cout << "8. ����� " << endl;
    cout << "����:";
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
            cout << "������� �����.";
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
                cout << "��������� ������:" << endl;
                printAllCustomers(list, size);
            }
            else {
                cout << "�������� �� �������." << endl;
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
            cout << "������� �����." << endl;
            break;
        }
    } while (cmd != 8);
}
