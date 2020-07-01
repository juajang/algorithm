#include <iostream>
using namespace std;

int N, K;
int coin[100], cache[10001];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	cache[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= coin[i]) cache[j] += cache[j - coin[i]];
		}
	}
	cout << cache[K] << "\n";
	return 0;
}