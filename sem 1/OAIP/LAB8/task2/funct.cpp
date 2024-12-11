#include <iostream>
#include "telephoneExchange.h"

call* copy(call* arr1, call* arr2, int countOfCalls) {
	for (int i = 0; i < countOfCalls; i++) {
		arr1[i] = arr2[i];
	}
	return arr1;
}

void printCities(int countOfCities, string cities[]) {
	for (int i = 0; i < countOfCities; i++) {
		cout << i + 1 << "." << cities[i] << endl;
	}
}

void printCall(call call) {
	cout << "data:" << call.data << endl;
	cout << "time:" << call.timeMIN << endl;
	cout << "tarif:" << call.tarif << endl;
	cout << "city:" << call.city << endl;
	cout << "code:" << call.code << endl;
	cout << "num:" << call.number << endl;
	cout << "numA:" << call.numberA << endl;

}

void printCalls(call* list, int countOfCalls) {
	for (int i = 0; i < countOfCalls; i++) {
		cout << (i + 1) << ")" << endl;
		printCall(list[i]);
		cout << endl;
	}
}

call* remove(call* list, int *countOfCalls) {
	printCalls(list, *countOfCalls);
	int ind;
	cout << "enter:";
	cin >> ind;
	ind--;
	call* newList = new call[*countOfCalls - 1];

	for (int i = 0, j = 0; i < *countOfCalls; i++) {
		if (i != ind) {
			newList[j] = list[i];
			j++;
		}
	}
	(*countOfCalls)--;
	return newList;
}


call* add(call* list, string cities[], int *countOfCities, string codes[], int* countOfCalls) {
	string data;
	string city;
	int timeMIN;
	float tarif;
	string code;
	string number;
	string numberA;

	cout << "data:";
	cin >> data;

	printCities(*countOfCities, cities);
	int ind;
	cout << "select city:";
	cin >> ind;
	city = cities[ind - 1];
	code = codes[ind - 1];

	cout << "timeMIN:";
	cin >> timeMIN;

	cout << "tarif:";
	cin >> tarif;

	cout << "number:";
	cin >> number;

	cout << "numberA:";
	cin >> numberA;

	call* newList = new call[*countOfCalls + 1];
	newList = copy(newList, list, *countOfCalls);
	newList[*countOfCalls] = call(data, city, timeMIN, tarif, code, number, numberA);
	(*countOfCalls)++;
	return newList;
}

call* change(call* list, string cities[], string codes[], int* countOfCities, int* countOfCalls) {
	printCalls(list, *countOfCalls);
	int ind;
	cout << "select call:";
	cin >> ind;
	ind--;
	call needCall = list[ind];


	cout << "1.data" << endl << "2.city" << endl << "3.time" << endl
		<< "4.tarif" << endl << "5.num" << endl << "6.numA" << endl << "select el:";

	int parametr;
	cin >> parametr;

	string tempText;

	if (parametr == 1) {
		cout << "enter:";
		cin >> tempText;
		needCall.data = tempText;
	}
	else if (parametr == 2) {
		printCities(*countOfCities, cities);
		int i;
		cout << "enter:";
		cin >> i;

		needCall.city = cities[i - 1];
		needCall.code = codes[i - 1];
	}
	else if (parametr == 3) {
		int time;
		cout << "enter:";
		cin >> time;

		needCall.timeMIN = time;
	}
	else if (parametr == 4) {
		float tarif;
		cout << "enter:";
		cin >> tarif;

		needCall.tarif = tarif;
	}
	else if (parametr == 5) {
		cout << "enter:";
		cin >> tempText;

		needCall.number = tempText;
	}
	else if (parametr == 6) {
		cout << "enter:";
		cin >> tempText;

		needCall.numberA = tempText;
	}
	list[ind] = needCall;

	return list;
}

void printAllInformation(call* list, string cities[], int countOfCalls, int countOfCities){
	for (int i = 0; i < countOfCities; i++) {
		float sum = 0;
		int time = 0;
		for (int j = 0; j < countOfCalls; j++) {
			if(list[j].city == cities[i]){
				sum += (list[j].timeMIN) * (list[j].tarif);
				time += list[j].timeMIN;
			}
		}
		cout << i << ")" << cities[i] << endl << "Sum:" << sum << endl 
			<< "Full time:" << time << endl << "--------------" << endl;
	}
}

