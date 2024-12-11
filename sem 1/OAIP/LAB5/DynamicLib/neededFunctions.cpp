#include <iostream>
#include <cmath>
using namespace std;

bool neededEl(double* arr, int size){
    bool res;
    if(size == 1) {
        return sin(arr[0]) > 0;
    }else {
        int size1 = size / 2;
        int size2 = size - size1;

        double* newArr1 = new double[size1];
        double* newArr2 = new double[size2];

        for (int i = 0; i < size; i++) {
            if(i < size1){
                newArr1[i] = arr[i];
            }else {
                newArr2[i-size1] = arr[i];
            }
        }

        return neededEl(newArr1, size1) || neededEl(newArr2, size2);
    }
}

extern "C" __declspec(dllexport) void runTask(){
    const double PI = 3.14159265358979323846;
    int n;
    
    cout << "N:";
    cin >> n;

    double* arr = new double[n];

    for (int i = 0; i < n; i++) {
        cout << "rad[" << i << "] :";
        cin >> arr[i];
    }

    neededEl(arr, n) == true ? cout << "true" : cout << "false";

    delete[] arr;
}