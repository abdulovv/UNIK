#include <iostream>
#include <string>
#include <fstream>
#include "telephoneExchange.h"

using namespace std;

int countOfCities = 3;
int countOfCalls = 3;

string cities[] = { "Minsk", "Borisov", "Orsha" };
string codes[] = { "+808", "+707", "+606" };

void menu(){
	cout << "1. Список звонков." << endl;
	cout << "2. Добавить звонок." << endl;
	cout << "3. Удалить звонок. " << endl;
	cout << "4. Изменить информацию о звонке." << endl;
	cout << "5. Вывести по каждому городу общее время разговоров с ним и сумму " << endl;
	cout << "6. Выход " << endl;
	cout << "Ввод:";
}

int main(){
	setlocale(0,"");
	auto* calls = new call[countOfCalls];

	calls[0] = call("12.05.23", "Minsk", 33, 1.33, "+808", "8888", "7743");
	calls[1] = call("4.05.23", "Borisov", 12, 1.75, "+707", "6666", "5553");
	calls[2] = call("7.05.23", "Orsha", 6, 2.4, "+606", "54321", "1110");

	int cmd;
	do {
		menu();
		cin >> cmd;

		switch (cmd){
		case 1:
			printCalls(calls, countOfCalls);
			break;
		case 2:
			calls = add(calls, cities, &countOfCities, codes, &countOfCalls);
			break;
		case 3:
			calls = remove(calls, &countOfCalls);
			break;
		case 4:
			calls = change(calls, cities, codes, &countOfCities, &countOfCalls);
			break;
		case 5:
			printAllInformation(calls, cities, countOfCalls, countOfCities);
			break;
		case 6:
			break;
		default:
			break;
		}

	} while(cmd != 6);





}