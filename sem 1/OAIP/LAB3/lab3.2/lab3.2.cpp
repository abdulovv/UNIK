#include <iostream>
using namespace std;
int main(){
    double sum=0,n=1,d=0;
    
    do {
        d = pow(2, -n) + pow(3, -n);
        sum = sum + d;
        n++;
        cout << d << endl;
    } while (d > pow(10,-3));
    cout << sum;
    return 0;
}
