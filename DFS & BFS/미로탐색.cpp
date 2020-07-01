#include <iostream>
#include <cstdio>
using namespace std;

int N, M;
int arr[101][101];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int ans = 102000;
int cnt = 1;
bool visited[101][101];
bool isout(int i, int j) { return i < 1 || i > N || j < 1 || j > M; }

void dfs(int y, int x) {
	visited[y][x] = 1;
	if (y == N && x == M) {
		if (cnt < ans) ans = cnt;
		visited[y][x] = 0;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (isout(ny, nx)) continue;
		if (!visited[ny][nx] && arr[ny][nx]) {
			cnt++;
			dfs(ny, nx);
		}
	}
	visited[y][x] = 0;
}

int main() {
	cin >> N >> M; 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}
	dfs(1,1);
	cout << ans;
}