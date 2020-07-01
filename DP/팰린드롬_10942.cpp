#include <iostream>
#include <string.h>
using namespace std;

int N, M, S, E, num[2001];
int cache[2001][2001];

bool isPalindrome(int S, int E) {
	int& ret = cache[S][E];
	if (ret != -1) return ret;
	for (int i = S, j = 0; i <= (S + E) / 2; i++, j++) {
		if (cache[S + j][E - j] != -1) return cache[S + j][E - j];
		if (num[S + j] != num[E - j]) {
			cache[S][E] = 0;
			return 0;
		}
	}
	cache[S][E] = 1;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	memset(cache, -1, sizeof(cache));
	cin >> M;
	while (M--) {
		cin >> S >> E;
		cout << isPalindrome(S, E) << "\n";
	}
	return 0;
}