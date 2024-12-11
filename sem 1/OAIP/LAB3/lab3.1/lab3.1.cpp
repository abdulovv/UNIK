#include <iostream>
using namespace std;
int main(){
    int a, b, n = 0, i = 1;
    while (i <= 30) {
        if (i % 2 != 0) {
            a = i;
            b = pow(i,2);
        }else{
            a = i / 2;
            b = pow(i,3);
        }
        
        n = n + pow((a-b),2);
        i++;
    }
    cout << n;
    return 0;
}
