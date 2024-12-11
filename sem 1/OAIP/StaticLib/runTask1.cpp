#include <iostream>
#include "getRoot.h";
#include "arrayFunctions.h";
void runTask1(){
    int size;

    std::cout << "Size:";
    std::cin >> size;

    double* a = new double[size];
    double* b = new double[size];

    fillArray(a, size, 'a');
    fillArray(b, size, 'b');

    for (int i = 0; i < size; i++) {
        std::cout << "x" << i << "=" << getRoot(a[i], b[i]) << std::endl;
        std::cout << std::endl;
    }
}