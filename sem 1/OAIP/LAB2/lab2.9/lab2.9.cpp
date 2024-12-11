#include <iostream>
#include <cmath>
using namespace std;
int main(){
    setlocale(0, "");
    int n, integerNumber;
    float z, a, x,fx,y;

    cout << "Введите z:";
    cin >> z;
    
    cout << "Введите a:";
    cin >> a;

    cout << "Введите n:";
    cin >> n;

    if (z < 1){
        x = pow(z, 2);
    }else {
        x = z + 1;

    }

    switch (n){
    case 1: fx = 2 * x; break;
    case 2: fx = pow(x, 3); break;
    case 3: fx = x / 3;  break;
    }


    integerNumber = fx + 1;

    y = a * log(1 + pow(x, 0.2)) + pow(cos(integerNumber), 2);

    cout << "y="<< y;

    
}
