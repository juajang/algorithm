#include <iostream>
using namespace std;

int N, arr[500][500], cache[500][500];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int ans;

int max(int a, int b) { return a > b ? a : b; }

int dfs(int i, int j) {
	int& ret = cache[i][j];
	if (ret != -1) return ret;
	ret = 1;
	for (int d = 0; d < 4; d++) {
		int ny = i + dir[d][0];
		int nx = j + dir[d][1];
		if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
		if (arr[i][j] < arr[ny][nx]) {
			ret = max(ret, dfs(ny, nx) + 1);
		}
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			cache[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(dfs(i, j), ans);
		}
	}
	cout << ans << "\n";
	return 0;
}