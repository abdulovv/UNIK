#include <iostream>
using namespace std;
int main(){
	int x, y;
	setlocale(0, "");

	cout << "Введите X:";
	cin >> x;

	cout << "Введите Y:";
	cin >> y;

	if (x == 0 || y == 0) {
		cout << "ERROR";
		return 0;
	}

	if (x%y == 0 || y%x==0){
		cout << "YES";
	}
	else {
		cout << "NO";
	}
		
}
