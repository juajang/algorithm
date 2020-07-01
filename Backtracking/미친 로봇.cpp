#include <iostream>
#include <string.h>
using namespace std;

int N, dirPer[4], s[14];
bool visited[50][50];
double ans = 0;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void dfs(int cnt, double per, int y, int x) {
	if (cnt == N) {
		ans += per;
		return;
	}
	for (int i = 0; i < 4; i++) {
		s[cnt] = i;
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (visited[ny][nx]) continue;
		double newPer = per * (dirPer[i] / 100.0);
		visited[ny][nx] = true;
		dfs(cnt + 1, newPer, ny, nx);
		visited[ny][nx] = false;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> dirPer[i];
	}
	memset(visited, false, sizeof(visited));
	visited[25][25] = true;
	dfs(0, 1.0, 25, 25);
	printf("% .10f", ans);
	return 0;
}