#include <iostream>
using namespace std;

const int INF = 0x7FFFFFFF;
int N;
int color[1000][3];
int cache[1000][3];

int min(int a, int b) { return a < b ? a : b; }

int painting(int n, int prev) {
	if (n == N) return 0;
	int& let = cache[n][prev];
	if (let != INF) return let;
	for (int i = 0; i < 3; i++) {
		if (i != prev) {
			let = min(painting(n + 1, i) + color[n][i], let);
		}
	}
	return let;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color[i][j];
			cache[i][j] = INF;
		}
	}
	int ans = min(painting(1, 0) + color[0][0], painting(1, 1) + color[0][1]);
	ans = min(painting(1, 2) + color[0][2], ans);
	cout << ans << "\n";
	return 0;
}