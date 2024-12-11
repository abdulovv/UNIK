#include "pch.h"
int multiply(int* arr, int size);
TEST(Test1) {
    int sum = 1;
    int* arr = new int [5];
    arr[0] = 5;
    arr[1] = 10;
    arr[2] = 15;
    arr[3] = 20;
    arr[4] = 25;
    if(multiply(arr,5) != 375000){
        FAIL();
    }
    
}

TEST(Test2) {
    int sum = 1;
    int* arr = new int[5];
    arr[0] = 0;
    arr[1] = 10;
    arr[2] = 15;
    arr[3] = 20;
    arr[4] = 25;
    if (multiply(arr, 5) != 0) {
        FAIL();
    }

}

TEST(Test3) {
    int sum = 1;
    int* arr = new int[5];
    arr[0] = 34;
    arr[1] = 11;
    arr[2] = 44;
    arr[3] = 8;
    arr[4] = 4;
    if (multiply(arr, 5) != 526592) {
        FAIL();
    }

}


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