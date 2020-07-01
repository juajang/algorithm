#include <iostream>
#include <string.h>
using namespace std;

int n, m;
int rec[1001][1001], cache[1001][1001];

int Min(int a, int b, int c) {
	a = a < b ? a : b;
	return a < c ? a : c;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf_s("%1d", &rec[i][j]);
		}
	}
	int ans = 0; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (rec[i][j]) {
				cache[i][j] = Min(cache[i - 1][j - 1], cache[i - 1][j], cache[i][j - 1]) + 1;
				if (ans < cache[i][j]) ans = cache[i][j];
			}
		}
	}
	cout << ans * ans << "\n";
	return 0;
}