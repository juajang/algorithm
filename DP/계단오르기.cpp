#include <iostream>
using namespace std;

int N;
int cache[300];
int str[300];
int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> str[i];
	}
	cache[0] = 0;
	cache[1] = str[1];
	cache[2] = max(str[2], str[1] + str[2]);
	for (int i = 3; i <= N; i++) {
		cache[i] = max(cache[i - 3] + str[i - 1] + str[i], cache[i - 2] + str[i]);
	}
	cout << cache[N];
}