#include <iostream>
#include <string.h>
using namespace std;

const int N = 360000;
int n, a, b, p[360001];
bool A[720001], B[360001];

void getPi() {
	int j = 0;
	for (int i = 1; i < N; i++) {
		while (j > 0 && B[i] != B[j]) {
			j = p[j - 1];
		}
		if (B[i] == B[j]) p[i] = ++j;
	}
}

string KMP() {
	int j = 0;
	for (int i = 0; i < N * 2; i++) {
		while (j > 0 && A[i] != B[j]) {
			j = p[j - 1];
		}
		if (A[i] == B[j]) {
			if (j == N - 1) return "possible";
			j++;
		}
	}
	return "impossible";
}

int main() {
	memset(A, false, sizeof(A));
	memset(B, false, sizeof(B));
	int t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		A[t] = 1;
		A[t + N] = 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> t;
		B[t] = 1;
	}
	getPi();
	cout << KMP() << "\n";
	return 0;
}