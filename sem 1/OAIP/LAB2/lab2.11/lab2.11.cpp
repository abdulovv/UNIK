#include <iostream>
#include <cmath>
using namespace std;
int main(){
    const string IMPOSSIBLEVALUE = "Значение данной характеристики не может быть меньше или равно нулю";
    double angle, side, inscridebRadius, circleRadius;
    setlocale(0,"");

    cout << "Введите длину стороны ромба:";
    cin >> side;

    if (side <= 0) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }
    
    cout << "Введите угол ромба(rad):";
    cin >> angle;

    if (angle <= 0) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    cout << "Введите радиус шара:";
    cin >> circleRadius;

    if (angle <= 0) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }


    inscridebRadius = side * sin(angle) / 2;

    if (inscridebRadius >= circleRadius) {
        cout << "Шар сможет пройти в отверстие.";
    }else {
        cout << "Шар не сможет пройти в отверстие.";
    }
    return 0;
}
