#include <iostream>
#include <queue>
using namespace std;

const int INF = 0x7FFFFFFF;
int W, H;
char map[100][100];
int visited[100][100]; //거울 개수 
int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

struct mirror {
	int y; int x; int dir; int mirror;
};
queue<mirror> q;
mirror start, fin;

void BFS() {
	queue<mirror> q;
	for (int i = 0; i < 4; i++) {
		q.push({ start.y,start.x,i,0 });
	}
	visited[start.y][start.x] = 0;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		int mirror = q.front().mirror;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + d[i][0];
			int nx = x + d[i][1];
			int nmirror = mirror;
			if (ny >= H || nx >= W || ny < 0 || nx < 0) continue;
			if (map[ny][nx] == '*') continue;
			if (dir != i) nmirror++;
			if (visited[ny][nx] >= nmirror) {
				visited[ny][nx] = nmirror;
				q.push({ ny,nx,i,nmirror });
			}
		}
	}
}

int main() {
	cin >> W >> H;
	bool tmp = false; 
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				if (!tmp) {
					start.y = i;
					start.x = j;
					tmp = true;
				}
				else {
					fin.y = i;
					fin.x = j;
				}
			}
			visited[i][j] = INF;
		}
	}
	BFS();
	cout << visited[fin.y][fin.x] << "\n";
	return 0;
}