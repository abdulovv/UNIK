#include <iostream>
#include "arrayFunctions.h";
using namespace std;

int multiply(int* arr, int size) {
    int res = 0;

    if (size != 0) {
        res = 1;
        for (int i = 0; i < size; i++) {
            res *= arr[i];
        }
    }
    return res;

}


int main() {
    int n, m;
    
    cout << "n:";
    cin >> n;
  
    cout << "m: ";
    cin >> m;
    int r = 0;
 
    int** nums = createMatrix(n, m);
    fillMatrix(nums, n, m);

    int indI = 0, indJ = 0;
    int count = 0;
    while (indI < n && indJ < m) {
        if (nums[indI][indJ] % 2 == 0) {
            count++;
        }
        indI++;
        indJ++;
    }

    int* arr = new int[count]; 

    indI = 0; 
    indJ = 0;
    int indD = 0;
    while (indI < n && indJ < m) {
        if (nums[indI][indJ] % 2 == 0) {
            arr[indD] = nums[indI][indJ];
            indD++;
        }
        indI++;
        indJ++;
    }


    printArray(arr, count);

    int mult = multiply(arr, count);
    
    cout << endl;
    cout << "res:" << mult;

    deleteMatrix(nums,n);
    delete[] arr;
}
