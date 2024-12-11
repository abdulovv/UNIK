#pragma once
#include <string>
using namespace std;

struct call{
    string data;
    string city;
    int timeMIN;
    float tarif;
    string code;
    string number;
    string numberA;

    call(string data, string city, int timeMIN, float tarif, string code, string number, string numberA) {
        this->data = data;
        this->city = city;
        this->timeMIN = timeMIN;
        this->tarif = tarif;
        this->code = code;
        this->number = number;
        this->numberA = numberA;
    }

    call() {
        timeMIN = 0;
    }
};


call* copy(call* arr1, call* arr2, int countOfCalls);

void printCities(int countOfCities, string cities[]);

void printCall(call call);

void printCalls(call* list, int countOfCalls);

call* remove(call* list, int* countOfCalls);

call* add(call* list, string cities[], int* countOfCities, string codes[], int* countOfCalls);

call* change(call* list, string cities[], string codes[], int* countOfCities, int* countOfCalls);

void printAllInformation(call* list, string cities[], int countOfCalls, int countOfCities);

