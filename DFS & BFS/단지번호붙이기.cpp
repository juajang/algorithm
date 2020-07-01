#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int N;
int map[25][25];
bool visited[25][25];
int ans = 0;
int dj[625];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

bool isout(int i, int j) { return i < 0 || i >= N || j < 0 || j >= N; }

void dfs(int i, int j) {
	visited[i][j] = true;
	dj[ans] += 1;
	for (int d = 0; d < 4; d++) {
		int ny = i + dir[d][0];
		int nx = j + dir[d][1];
		if (isout(ny, nx)) continue;
		if (!visited[ny][nx] && map[ny][nx]) { dfs(ny, nx); }
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && !visited[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}
	sort(dj, dj + ans);
	cout << ans << "\n";
	for (int i = 0; i < ans; i++) {
		cout << dj[i] << "\n";
	}
	return 0;
}