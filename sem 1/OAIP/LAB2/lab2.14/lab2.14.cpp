#include <iostream>
#include <cmath>
using namespace std;
int main(){
    setlocale(0,"");
    const string IMPOSSIBLEVALUE = "Размерность данной величены не может быть меньше или равно нулю, не может находиться за пределом комнаты.";
    float x1, x2, y1, y2, wOFroom, hOFroom, wOFtable, hOFtable, minDistance, wDistance, hDistance;
    
    cout << "Введите ширину комнаты:";
    cin >> wOFroom;

    if(wOFroom <= 0){
        cout << IMPOSSIBLEVALUE;
        return 0;
    }
    
    cout << "Введите высоту комнаты:";
    cin >> hOFroom;

    if (hOFroom <= 0) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    cout << "Введите x1 основного стола:";
    cin >> x1;

    if (x1 < 0 || x1 > wOFroom) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    cout << "Введите у1 основного стола:";
    cin >> y1;

    if (y1 < 0 || y1 > hOFroom) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    cout << "Введите x2 основного стола:";
    cin >> x2;

    if (x2 < 0 || x2 > wOFroom) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    cout << "Введите у2 основного стола:";
    cin >> y2;

    if (y2 < 0 || y2 > hOFroom) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    cout << "Введите ширину второго стола:";
    cin >> wOFtable;

    if (wOFtable <= 0 || wOFtable > wOFroom) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    cout << "Введите высоту второго стола:";
    cin >> hOFtable;

    if (hOFtable <= 0 || hOFtable > hOFroom) {
        cout << IMPOSSIBLEVALUE;
        return 0;
    }

    if (x2<x1) { 
        float x3;
        x3 = x1;
        x1 = x2;
        x2 = x3;
    }
    if (y2 < y1) {
        float y3;
        y3 = y1;
        y1 = y2;
        y2 = y3;
    }


    minDistance = wOFroom + hOFroom;
    wDistance = wOFtable - x1;
    hDistance = hOFtable - y1;

    if (wDistance > hDistance && y2 + hDistance <= hOFroom) {
        minDistance = hDistance;
    }

    if (wDistance < hDistance && x2 + wDistance <= wOFroom) {
        minDistance = wDistance;
    }

    hDistance = y2 - (hOFroom-hOFtable);

    if (hDistance < minDistance && y1 - hDistance >= 0) {
        minDistance = hDistance;
    }

    wDistance = x2 - (wOFroom-wOFtable);

    if (wDistance < minDistance && x1 - wDistance >= 0) {
        minDistance = wDistance;
    }

    if (minDistance == wOFroom + hOFroom) {
        cout << "Невозможно расположить два стола.";
        
    }else if (minDistance <= 0) {
        cout << "Перестановки не требуются, столы друг другу не мешают.";
    }else {
        cout << "Минимальный сдвиг:" << minDistance;
    }


}
