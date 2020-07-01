#include <iostream>
#include <string>
#include <queue>
using namespace std;

int map[1001][1001];
int visited[1001][1001][2];
int N, M;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
 
struct visit {
	int y;
	int x;
	int wall;
};

bool isout(int a, int b) { return a > N || a < 1 || b > M || b < 1; }

int bfs() {
	queue<visit> q; 
	q.push({ 1,1,1 });
	visited[1][1][1] = 1;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int wall = q.front().wall;
		q.pop();
		if (y == N && x == M) {
			return visited[y][x][wall];
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			if (isout(ny, nx)) continue;
			if (visited[ny][nx][wall]) continue; 
			if (map[ny][nx] == 0) {
				q.push({ ny,nx,wall });
				visited[ny][nx][wall] = visited[y][x][wall] + 1;
			}
			if (map[ny][nx] == 1 && wall == 1) {
				q.push({ny,nx,0});
				visited[ny][nx][0] = visited[y][x][1] + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		string str;
		cin >> str;
		for (int k = 0; k < M; k++){
			map[i][k] = str[k] - '0';
		}
	}
	cout << bfs();
	return 0;
}