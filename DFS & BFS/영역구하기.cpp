#include <iostream>
#include <algorithm>
using namespace std;

int M, N, K;
int rec[100][100];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int ans[10000];

bool isout(int y, int x) { return y < 0 || y >= M || x < 0 || x >= N; }

void print(int cnt) {
	cout << cnt << ": " << ans[cnt] << "\n";
	for (int i = M - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			cout << rec[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
void dfs(int y, int x, int cnt) {
	rec[y][x] = 1;
	ans[cnt] += 1; 
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (isout(ny, nx)) continue;
		if (rec[ny][nx]==0) dfs(ny, nx, cnt);
	}
}
int main() {
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				rec[i][j] = 2;
			}
		}
	}

	int cnt = 0;
	for (int i = M - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (rec[i][j] == 0) dfs(i, j, cnt++);
		}
	}

	cout << cnt << "\n";
	sort(ans, ans + cnt);
	for (int i = 0; i < cnt; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}

