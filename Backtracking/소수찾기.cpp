#include <iostream>
#include <cmath>
using namespace std;

int N, n;
int ans = 0;

bool isPrime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i <= ceil(sqrt(n)); i++) {
		if (n%i == 0) return false;
	}
	return true;
}

int main() {
	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (isPrime(n)) ans++;
	}
	cout << ans;
	return 0;
}