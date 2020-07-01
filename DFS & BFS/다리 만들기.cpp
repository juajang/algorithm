#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int N, map[100][100], mark[100][100], visited[100][100], ans = 10000, idx = 0;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

vector<pair<int, int>> brStart[10000];

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
		if (map[ny][nx] && mark[ny][nx] == 0) {
			mark[ny][nx] = idx; //섬 번호 매기기 
			dfs(ny, nx);
		}
		else if (!map[ny][nx] && mark[ny][nx] == 0) {
			brStart[idx].push_back(make_pair(ny, nx));
		}
	}
}

void connectBr(int y, int x, int cost, int now) {
	if (cost > ans) return;
	cost++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
		if (!mark[ny][nx] && visited[ny][nx] > cost) {
			visited[ny][nx] = cost;
			connectBr(ny, nx, cost, now);
		}
		else if (mark[ny][nx] >= 1 && now != mark[ny][nx]) {
			if (ans > cost) {
				ans = cost;
				visited[ny][nx] = cost;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	memset(mark, 0, sizeof(mark));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] && mark[i][j] == 0) {
				mark[i][j] = ++idx;
				dfs(i, j);
			}
		}
	}
	for (int i = 1; i <= idx; i++) {
		for (int j = 0; j < brStart[i].size(); j++) {
			int y = brStart[i][j].first;
			int x = brStart[i][j].second;
			memset(visited, 0x7f, sizeof(visited));
			visited[y][x] = 0;
			connectBr(y, x, 0, i);
		}
	}
	cout << ans << "\n";
	return 0;
}