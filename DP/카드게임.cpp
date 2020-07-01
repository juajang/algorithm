#include <iostream>
#include <string.h>
using namespace std;

int N;
int A[2000], B[2000], cache[2000][2000];

int max(int a, int b) { return a > b ? a : b; }

int card(int a, int b) {
	if (a >= N || b >= N) return 0;
	int& ret = cache[a][b];
	if (ret != -1) return ret;
	ret = max(card(a + 1, b + 1), card(a + 1, b));
	if (A[a] > B[b]) ret = max(ret, card(a, b + 1) + B[b]);
	//printf("a: %d b: %d ret: %d\n", a, b, ret);
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	cout << card(0, 0);
	return 0;
}