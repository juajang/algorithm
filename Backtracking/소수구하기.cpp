#include <iostream>
#include <cmath>
using namespace std;

int M, N;
bool notPrime[1000000];

int main() {
	cin >> M >> N;
	notPrime[1] = true;
	for (int j = 2; j <= ceil(sqrt(N)); j++) {
		int n = 2;
		while (j*n <= N) {
			if (j*n >= M) notPrime[j*n] = true;
			n++;
		}
	}
	for (int i = M; i <= N; i++) {
		if (!notPrime[i]) cout << i << "\n";
	}
	return 0;
}