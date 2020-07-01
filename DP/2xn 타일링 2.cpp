#include <iostream>
using namespace std;

int n;
int cache[1001];

int main() {
	cin >> n;
	cache[1] = 1;
	cache[2] = 3;

	for (int i = 3; i <= n; i++) {
		cache[i] = (cache[i - 1] + cache[i - 2]*2) % 10007;
	}
	cout << cache[n] << "\n";
	return 0;
}