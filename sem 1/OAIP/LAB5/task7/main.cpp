#include <iostream>
using namespace std;

unsigned long long binaryPow(long long k, long long n, unsigned long long m){
	
	if (n == 1) {
		return k;    
	}

	if (n % 2 == 0) {
		long long t = binaryPow(k, n / 2, m);
		return t * t % m;
	}
	else {
		return binaryPow(k, n - 1, m) * k % m;
	}
}

int main(){
	unsigned long long n, k, t;

	int rep = 1;
	while (1){
		cout << "k:";
		cin >> k;

		cout << "n:";
		cin >> n;

		cout << "t:";
		cin >> t;

		if( k == 0 && n == 0 && t == 0){
			break;
		}

		cout << "Case #"<<rep<<":" << binaryPow(k, n, pow(10, t))<<endl;
		rep++;

	} 
}