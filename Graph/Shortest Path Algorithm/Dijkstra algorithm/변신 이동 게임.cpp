#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int N, t, r, c;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
char map[501][501];
int dist[501][501][2];

struct Move {
	int cost;
	int trans;
	int y;
	int x;
};

struct cmp {
	bool operator()(Move a, Move b) {
		return a.cost > b.cost;
	}
};

bool isOut(int a, int b) { return a < 1 || a > N || b < 1 || b > N; }

int main() {
	cin >> N >> t >> r >> c;
	string str;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			dist[i][j][0] = dist[i][j][1] = INF;
		}
	}

	priority_queue<Move, vector<Move>, cmp> Q;
	dist[1][1][0] = 0;
	Q.push({ 0, 0, 1, 1 });

	while (!Q.empty()) {
		int cost = Q.top().cost;
		int trans = Q.top().trans;
		int y = Q.top().y;
		int x = Q.top().x;
		Q.pop();

		if (dist[y][x][trans] < cost) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			if (isOut(ny, nx)) continue;
			if (cost + 1 < dist[ny][nx][0]) {
				dist[ny][nx][0] = cost + 1;
				Q.push({ cost + 1, 0, ny, nx });
			}
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			while (!isOut(ny, nx) && map[ny][nx] != '#') {
				ny += dir[i][0];
				nx += dir[i][1];
			}

			if (!isOut(ny, nx)) {
				int nextCost = trans == 1 ? cost + 1 : cost + 1 + t;
				if (nextCost < dist[ny][nx][1]) {
					dist[ny][nx][1] = nextCost;
					Q.push({ nextCost, 1, ny, nx });
				}
			}
		}
	}

	cout << min(dist[r][c][0], dist[r][c][1]) << endl;
	return 0;
}