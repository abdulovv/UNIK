#include <iostream>
using namespace std;

long long divider(long long num){
	if(num % 2 != 0){
		return num;
	}
	
	do{
		num /= 2;
	} while (num % 2 == 0);
	return num;	
}

long long sum(long long num){
	long long res = 0;
	for (long long i = 1; i <= num; i++) {
		res += divider(i);
	}
	return res;
}

int main(){
	int k;

	cout << "k:";
	cin >> k;

	long long* n = new long long[k];
	
	for (int i = 0; i < k; i++) {
		cin >> n[i];
	}

	cout << endl;
	
	for (int i = 0; i < k; i++) {
		cout << sum(n[i]) << endl;
	}

}