#include <iostream> 

void fillMatrix(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << "matrix" << "[" << i << "]" << "[" << j << "] :";
            std::cin >> arr[i][j];
        }
        std::cout << std::endl;
    }
}

void fillMatrix(double** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << "matrix" << "[" << i << "]" << "[" << j << "] :";
            std::cin >> arr[i][j];
        }
        std::cout << std::endl;
    }
}

int** createMatrix(int n, int m) {
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    return arr;
}

double** createMatrixDouble(int n, int m) {
    double** arr = new double* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[m];
    }
    return arr;
}

void printMatrix(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printMatrix(double** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void fillArray(int* arr, int size, char lable) {
    for (int i = 0; i < size; i++) {
        std::cout << lable << i << ":";
        std::cin >> arr[i];
    }
}

void fillArray(double* arr, int size, char lable) {
    for (int i = 0; i < size; i++) {
        std::cout << lable << i << ":";
        std::cin >> arr[i];
    }
}

void printArray(int* arr, int size){
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if(i != size-1 ){
            std::cout << ", ";
        }
    }
}

void printArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i != size - 1) {
            std::cout << ", ";
        }
    }
}

void deleteMatrix(int** arr, int size){
    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void deleteMatrix(double** arr, int size) {
    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}


