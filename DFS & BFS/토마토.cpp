#include <iostream>
#include <queue>
using namespace std;

int M, N;
int box[1000][1000];
bool visited[1000][1000];
int ans = 0;
queue<pair<int, int>> q;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

bool isout(int y, int x) { return y >= N || y < 0 || x >= M || x < 0; }

void bfs() {
	while (!q.empty()) {
		int qsize = q.size();
		for(int i=0; i<qsize; i++) {
			int y = q.front().first;
			int x = q.front().second;
			visited[y][x] = true;
			q.pop();
			for (int d = 0; d < 4; d++) {
				int ny = y + dir[d][0];
				int nx = x + dir[d][1];
				if (isout(ny, nx) || visited[ny][nx]) continue;
				if (box[ny][nx] == 0) {
					box[ny][nx] = 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
		ans++;
	}
}
int main() {
	cin >> M >> N;
	bool check = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) q.push(make_pair(i,j));
			if (box[i][j] == 0) check = false;
		}
	}
	if (check) cout << "0";
	else {
		bfs();
		check = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (box[i][j] == 0) check = false;
			}
		}
		if (check) cout << ans-1;
		else cout << -1;
	}
	return 0;
}