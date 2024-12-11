#include <iostream>
using namespace std;
int F(int n){
	if(n % 10 > 0){
		return (n % 10);
	}else if(n == 0){
		return 0;
	}
	return F(n / 10);
}

int S(int p, int q){
	int sum = 0;

	for (int i = p; i <= q; i++) {
		sum += F(i);
	}
	return sum;
}

int main(){
	int sum = 0;
	int p, q;
	
	cout << "p:";
	cin >> p;
	
	cout << "q:";
	cin >> q;

	while (1) {
		cout << "p:";
		cin >> p;

		cout << "q:";
		cin >> q;

		if (p == -1 && q == -1) {
			break;
		}
		
		cout << "sum:" << S(p, q) << endl;
	}

	
}