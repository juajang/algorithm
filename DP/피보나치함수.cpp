#include <iostream>
#include <string.h>
using namespace std;

int T;
int zero, one; 
int cache[40];

int fibonacci(int n) {
	int& ret = cache[n];
	if (ret!=-1) return ret;
	return ret = fibonacci(n-1) + fibonacci(n-2);
}

int main() {
	cin >> T;
	int tmp;
	memset(cache, -1, sizeof(cache));
	cache[0] = 1;
	cache[1] = 1;
	for (int i = 0; i < T; i++) {
		zero = 0;
		one = 0;
		cin >> tmp;
		fibonacci(tmp);
		if (tmp == 0) cout << "1 0\n";
		else if (tmp == 1) cout << "0 1\n";
		else {
			fibonacci(tmp);
			cout << cache[tmp - 2] << " " << cache[tmp - 1] << "\n";
		}
	}
	return 0; 
}