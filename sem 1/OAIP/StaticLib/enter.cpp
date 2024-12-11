#include <iostream>
#include <cmath>
using namespace std;

int charToInt(const char* num) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (num[0] == '-') {
        sign = -1;
        i = 1;
    }

  
    while (num[i] != '\0') {
        if (num[i] >= '0' && num[i] <= '9') {
            int digit = num[i] - 48;
            result = result * 10 + digit;
        }else {
            return 0;
        }

        i++;
    }

    return sign * result;
}

bool isInputValidINT(const char* input, const int size) {
    int siz = 11;
    if (input[0] == '\0') {
        return false;
    }

    int n1[] = {2,1,4,7,4,8,3,6,4,7};

    // сделать минус
    int l = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if(input[i] == '-') {
            siz++;
            l++;
            continue;
        }
        if (!(input[i] >= '0' && input[i] <= '9') || i > siz) {
            return false;
        }  
        l++;
    }

    if(l == 11){
        int n2[10];
        for (int i = 0; i < siz; i++) {
            n2[i] = input[i] - 48;
        }

        for (int i = 0; i < siz; i++) {
            if (n1[i] > n2[i]) {
                return true;
            }
            else if (n1[i] < n2[i]) {
                return false;
            }
        }

    }


    

    return true;
}


