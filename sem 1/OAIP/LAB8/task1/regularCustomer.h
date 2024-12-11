#pragma once
#include <string>

struct customer {
	std::string surname;
	std::string name;
	std::string address;
	int discount;

	customer(std::string surname, std::string name, std::string address, int discount){
		this->surname = surname;
		this->name = name;
		this->address = address;
		this->discount = discount;
	}

	customer() {
		discount = 0;
	}
};

void startArray(customer* customers);

void printAllCustomers(customer* customers, int size);

void printCustomer(customer cstmr);

void printPercent5(customer* customers, int* currentLength);

customer* addNewClient(customer* customers, int* currentLength);

customer* search(customer* customers, bool* found, int* size, int* currentLength);

customer* remove(customer* customers, int* currentLength);

customer* change(customer* customers, int* currentLength);

customer* sort(customer* customers, int* currentLength);
