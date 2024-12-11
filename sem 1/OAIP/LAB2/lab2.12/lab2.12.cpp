#include <iostream>
using namespace std;
int main(){
    setlocale(0,"");
    const string IMPOSSIBLEVALUE = "Данная характеристика не может быть меньше или равна 0";
    float sideOfBrick1, sideOfBrick2, sideOfBrick3, sideOfHole1, sideOfHole2, squareOfBrick1, squareOfBrick2, squareOfBrick3,squareOfHole;

    cout << "Введите 1е ребро кирпича:";
    cin >> sideOfBrick1;

    if (sideOfBrick1 <= 0) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    cout << "Введите 2е ребро кирпича:";
    cin >> sideOfBrick2;

    if (sideOfBrick2 <= 0) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    cout << "Введите 3е ребро кирпича:";
    cin >> sideOfBrick3;

    if (sideOfBrick3 <= 0) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    cout << "Введите длину отверстия:";
    cin >> sideOfHole1;

    if (sideOfHole1 <= 0) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    cout << "Введите ширину отверстия:";
    cin >> sideOfHole2;

    if (sideOfHole2 <= 0) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    squareOfBrick1 = sideOfBrick1 * sideOfBrick2;
    squareOfBrick2 = sideOfBrick1 * sideOfBrick3;
    squareOfBrick3 = sideOfBrick2 * sideOfBrick3;
    squareOfHole = sideOfHole1 * sideOfHole2;


    if (squareOfBrick1 <= squareOfHole && squareOfBrick2 <= squareOfHole && squareOfBrick3 <= squareOfHole) {
        cout << "Кирпич пройдет в отверстие";
    }else{
        cout << "Кирпич не пройдет в отверстие";
    }


    return 0;


}
