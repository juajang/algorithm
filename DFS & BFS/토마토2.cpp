#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
int box[100][100][100];
int ans = 0;

int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int dh[] = { 0, 0, 0, 0, 1, -1 };

struct tomato {
	int y;
	int x; 
	int h;
};
queue<tomato> q;

bool isout(int a, int b, int c) { return a < 0 || b < 0 || c < 0 || a >= N || b >= M || c >= H; }

void bfs() {
	while (!q.empty()) {
		ans++;
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int y = q.front().y;
			int x = q.front().x;
			int h = q.front().h;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				int nh = h + dh[i];
				if (isout(ny, nx, nh)) continue;
				if (box[ny][nx][nh] == 0) {
					box[ny][nx][nh] = 1;
					q.push({ ny,nx,nh });
				}
			}
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> M >> N >> H;
	bool isFinish = true;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[j][k][i];
				if (box[j][k][i] == 1) q.push({ j,k,i });
				if (box[j][k][i] == 0) isFinish = false;
			}
		}
	}
	if (isFinish) cout << 0;
	else {
		bfs();
		isFinish = true;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (box[j][k][i] == 0) isFinish = false;
				}
			}
		}
		if (isFinish) cout << ans-1;
		else cout << -1;
	}
	return 0;
}