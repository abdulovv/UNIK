#include <iostream>
#include <cmath>
using namespace std;
int main(){
    setlocale(0,"");
    float a, b, c, y;
    int n;

    cout << "Введите a:";
    cin >> a;

    cout << "Введите b:";
    cin >> b;
    
    cout << "Введите c:";
    cin >> c;

    cout << "Введите N:";
    cin >> n;

    switch (n){
    case 2:
        y = b*c - pow(a,2);
        break;
    case 56:
        y = b * c;
        break;
    case 7:
        y = pow(a,2) + c;
        break;
    case 3:
        y = a - b * c;
        break;
    default:
        y = pow((a + b), 3);
        break;
    }
    
    cout << "Y=" << y;
    
}
