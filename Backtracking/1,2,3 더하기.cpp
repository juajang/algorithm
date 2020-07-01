#include <iostream>
using namespace std;

int T, n; 
int ans;

void sum(int n) {
	if (n == 0) {
		ans++;
		return;
	}
	if (n < 0) return;
	for (int i = 1; i <= 3; i++) {
		sum(n-i);
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		sum(n);
		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}