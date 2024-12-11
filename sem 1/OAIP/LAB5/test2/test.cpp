#include "pch.h"

double** reverse(double** nums, int n, int m) {
    double** reverseNums = new double* [n];
    for (int i = 0; i < n; i++) {
        reverseNums[i] = new double [m];
    }
    int sizeN = n - 1;
    int sizeM = m - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            reverseNums[i][j] = nums[sizeN][sizeM];
            sizeM--;
        }
        sizeN--;
        sizeM = m - 1;
    }
    return reverseNums;
}

TEST(Test1) {
    double** arr = new double* [2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new double[2];
    }

    arr[0][0] = 5;
    arr[0][1] = 15;
    arr[1][0] = 25;
    arr[1][1] = 35;

    
    double** revArr = reverse(arr, 2,2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if(arr[i][i] != revArr[1-i][1-i]) {
                FAIL();
            }
        }
    }


}

