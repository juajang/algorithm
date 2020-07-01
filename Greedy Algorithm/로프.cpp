#include <iostream>
#include <algorithm>
using namespace std;

int N;
int rope[100000];
int ans = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + N, greater<int>());
	for (int i = 1; i <= N; i++) {
		if (ans < rope[i-1] * i) ans = rope[i-1] * i;
	}
	cout << ans;
	return 0;
}