#include <iostream>
using namespace std;

int N, K;
int cache[201][201];

int main() {
	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		cache[i][1] = 1;
		for (int k = 2; k <= K; k++) {
			for (int j = 0; j <= i; j++) {
				cache[i][k] = (cache[i][k] + cache[i - j][k - 1]) % 1000000000;
				//printf("i: %d k: %d j: %d cache: %d\n", i, k, j, cache[i][k]);
			}
		}
	}
	cout << cache[N][K] << "\n";
	return 0;
}