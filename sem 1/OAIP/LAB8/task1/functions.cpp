#include <iostream>
#include "regularCustomer.h"

using namespace std;

bool isGoodEnter(string text){
    for (int i = 0; text[i] != '\0'; i++) {
        int n = (int)text[i];
        if( !((n >= 65 && n <= 90) || (n >= 97 && n <= 122)) ){
            return false;
        }
    }
    return true;
}

void startArray(customer* customers){
	customers[0] = customer("akulich","limon","kamenka",5);
	customers[1] = customer("abd", "toha", "fizk", 76);
	customers[2] = customer("abdulov", "elisey", "domik", 5);
}

void printAllCustomers(customer* customers, int size) {
    for (int i = 0; i < size; i++) {
        cout << "----------------- " << endl;
        cout << (i + 1) << ")" << endl << "�������:" << customers[i].surname << endl;
        cout << "���:" << customers[i].name << endl;
        cout << "�����:" << customers[i].address << endl;
        cout << "������:" << customers[i].discount << endl;
        cout << endl;
    }
}

void printCustomer(customer cstmr) {
    cout << "-----------------" << endl;
    cout << "�������:" << cstmr.surname << endl;
    cout << "���:" << cstmr.name << endl;
    cout << "�����:" << cstmr.address << endl;
    cout << "������:" << cstmr.discount << endl;
}

bool isText1NeedToSwap(string text1, string text2) {
    int size;

    if (text1.length() >= text2.length()) {
        size = text2.length();
    }
    else {
        size = text1.length();
    }

    for (int i = 0; i < size; i++) {
        int ch1 = tolower(text1[i]);
        int ch2 = tolower(text2[i]);
        if (ch1 < ch2) {
            return true;
        }
        else if (ch1 > ch2) {
            return false;
        }
    }

    return text1.length() > text2.length();
}

static bool equals(customer cstmr1, customer cstmr2) {
    if (cstmr1.surname == cstmr2.surname && cstmr1.name == cstmr2.name &&
        cstmr1.address == cstmr2.address && cstmr1.discount == cstmr2.discount)
        return true;
    return false;
}

static customer* addExistingCstmr(customer* list, customer cstmr, int size) {
    auto newList = new customer[size + 1];
    for (int i = 0; i < size; i++)
        newList[i] = list[i];

    newList[size] = cstmr;

    return newList;
}

customer* addNewClient(customer* customers, int* currentLength) {
    (*currentLength)++;
    auto newList = new customer[*currentLength];
    string name, surname, address;
    int discount;

  
    cout << "������� �������: ";
    cin >> surname;

    cout << "������� ���:";
    cin >> name;

    cout << "������� �����:";
    cin >> address;

    cout << "������� ������:";
    while (!(cin >> discount) && (cin.peek() != '\n')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������� �����.";
    }

    for (int i = 0; i < *currentLength - 1; i++)
        newList[i] = customers[i];

    newList[*currentLength - 1] = customer(surname, name, address, discount);

    return newList;
}

customer* remove(customer* customers, int* currentLength) {
    int size = 0;
    bool found = false;
    auto removeList = new customer[size];
    removeList = search(customers, &found, &size, currentLength);

    int finalSize = *currentLength - 1;
    auto finalList = new customer[finalSize];

    if (!found) {
        cout << "�������� �� �������." << endl;
        delete[] removeList;
        delete[] finalList;
        return customers;
    }
    customer needCstmr;
    if (size > 1) {
        printAllCustomers(removeList, size);
        int ind;
        cout << "�������� ����� �������, �������� ������ �������:";
        cin >> ind;
        needCstmr = removeList[ind - 1];
    }
    else {
        needCstmr = removeList[0];
    }

    for (int i = 0, j = 0; i < *currentLength; i++) {
        auto currentCstmr = customers[i];
        if (!equals(currentCstmr, needCstmr))
            finalList[j++] = currentCstmr;
    }
    *currentLength = finalSize;
    customers = finalList;
    return customers;
}

customer* change(customer* customers, int* currentLength) {
    int size = 0;
    bool found = false;
    auto changeList = new customer[size];
    cout << "������� ������� �� ��������� ���-���." << endl;
    changeList = search(customers, &found, &size, currentLength);

    if (!found) {
        cout << "�������� �� �������." << endl;
        delete[] changeList;
        return customers;
    }

    customer needCstmr;
    if (size > 1) {
        printAllCustomers(changeList, size);
        int ind;
        cout << "�������� ����� �������, �������� ������ �������� ������:";
        cin >> ind;
        needCstmr = changeList[ind - 1];
    }
    else {
        needCstmr = changeList[0];
        printCustomer(needCstmr);
    }

    for (int i = 0; i < *currentLength; i++) {
        auto currentCstmr = customers[i];
        if (equals(currentCstmr, needCstmr)) {
            int parameter, discount;
            string tempText;

            cout << "����� ������ �� ������ ��������:" << endl << "1. ������� " << endl
                << "2. ��� " << endl << "3. ����� " << endl << "4. ������ " << endl << "����:";
            cin >> parameter;

            if (parameter == 1) {
                cout << "����� �������:";
                cin >> tempText;
                customers[i].surname = tempText;
            }
            else if (parameter == 2) {
                cout << "����� ���:";
                cin >> tempText;
                customers[i].name = tempText;
            }
            else if (parameter == 3) {
                cout << "����� �����:";
                cin >> tempText;
                customers[i].address = tempText;
            }
            else if (parameter == 4) {
                cout << "����� ������:";
                cin >> discount;
                customers[i].discount = discount;
            }
            break;
        }
    }
    return customers;
}

customer* search(customer* customers, bool* found, int* size, int* currentLength) {
    int finalSize = 0, parameter, discount;
    auto foundCustomers = new customer[*size];
    string tempText;
    cout << "1. ������� " << endl << "2. ��� " << endl << "3. ����� "
        << endl << "4. ������ " << endl << "����:";
    cin >> parameter;

    switch (parameter) {
    case 1:
        cout << "������� �������:";
        cin >> tempText;
        for (int i = 0; i < *currentLength; i++) {
            customer currentCstmr = customers[i];
            if (customers[i].surname == tempText) {
                foundCustomers = addExistingCstmr(foundCustomers, currentCstmr, finalSize++);
                *found = true;
            }
        }

        break;
    case 2:
        cout << "������� ���:";
        cin >> tempText;
        for (int i = 0; i < *currentLength; i++) {
            customer currentCstmr = customers[i];
            if (customers[i].name == tempText) {
                foundCustomers = addExistingCstmr(foundCustomers, currentCstmr, finalSize++);
                *found = true;
            }
        }
        break;
    case 3:
        cout << "������� �����:";
        cin >> tempText;

        for (int i = 0; i < *currentLength; i++) {
            customer currentCstmr = customers[i];
            if (customers[i].address == tempText) {
                foundCustomers = addExistingCstmr(foundCustomers, currentCstmr, finalSize++);
                *found = true;
            }
        }
        break;
    case 4:
        cout << "������� ������:";
        cin >> discount;

        for (int i = 0; i < *currentLength; i++) {
            customer currentCstmr = customers[i];
            if (currentCstmr.discount == discount) {
                foundCustomers = addExistingCstmr(foundCustomers, currentCstmr, finalSize++);
                *found = true;
            }
        }
        break;
    default:
        break;
    }
    *size = finalSize;
    return foundCustomers;
}

customer* sort(customer* customers, int* currentLength) {
    int parameter;
    cout << "����������� �� ���������:" << endl << "1. ������� " << endl << "2. ��� "
        << endl << "3. ����� " << endl << "4. ������ " << endl << "����:";

    cin >> parameter;

    if (parameter == 1) {
        for (int i = 0; i < *currentLength; i++) {
            for (int j = 0; j < *currentLength; j++) {
                string sur1 = customers[i].surname;
                string sur2 = customers[j].surname;
                if (isText1NeedToSwap(sur1, sur2)) {
                    customer tempCstmr = customers[i];
                    customers[i] = customers[j];
                    customers[j] = tempCstmr;
                }
            }
        }
    }
    else if (parameter == 2) {
        for (int i = 0; i < *currentLength; i++) {
            for (int j = 0; j < *currentLength; j++) {
                string sur1 = customers[i].name;
                string sur2 = customers[j].name;
                if (isText1NeedToSwap(sur1, sur2)) {
                    customer tempCstmr = customers[i];
                    customers[i] = customers[j];
                    customers[j] = tempCstmr;
                }
            }
        }
    }
    else if (parameter == 3) {
        for (int i = 0; i < *currentLength; i++) {
            for (int j = 0; j < *currentLength; j++) {
                string sur1 = customers[i].address;
                string sur2 = customers[j].address;
                if (isText1NeedToSwap(sur1, sur2)) {
                    customer tempCstmr = customers[i];
                    customers[i] = customers[j];
                    customers[j] = tempCstmr;
                }
            }
        }
    }
    else if (parameter == 4) {
        for (int i = 0; i < *currentLength; i++) {
            for (int j = 0; j < *currentLength; j++) {
                if (customers[i].discount > customers[j].discount) {
                    customer tempCstmr = customers[i];
                    customers[i] = customers[j];
                    customers[j] = tempCstmr;
                }
            }
        }
    }
    return customers;
}

void printPercent5(customer* customers, int* currentLength){
    bool isFound = false;
    for (int i = 0; i < *currentLength; i++) {
        if(customers[i].discount == 5) {
            isFound = true;
            printCustomer(customers[i]);
        }
    }
    if(!isFound){
        cout << "�������� �� �������." << endl;
    }
}