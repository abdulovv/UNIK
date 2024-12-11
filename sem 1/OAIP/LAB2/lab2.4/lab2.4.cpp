#include <iostream>
using namespace std;
int main(){
	float x, y;
	setlocale(0,"");
	
	cout << "Введите X:";
	cin >> x;

	cout << "Введите Y:";
	cin >> y;

	/*
	bool firstBigger = x > y;
	cout << "" << endl;

	firstBigger ? cout << "x>y": cout << "x<y";
	*/

	x>y ? cout << "x>y" : cout << "x<y";

	

	
}
