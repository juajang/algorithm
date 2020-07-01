#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f;
int N, M, S, K, parent[251], visited[50][50], ans = 0, cnt = 0;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
char maze[50][50];

struct key {
	int y; int x; int cost;
};
bool operator<(const key& a, const key& b) {
	return a.cost < b.cost;
}

vector<key> node, graph;

int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	parent[x] = y;
}

int calcDist(int a, int b) {
	queue<key> q;
	memset(visited, 0, sizeof(visited));
;	int y = node[a].y, x = node[a].x, cost;
	int destY = node[b].y, destX = node[b].x;
	q.push({ y,x,0 });
	visited[y][x] = 1;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		cost = q.front().cost;
		q.pop();
		if (y == destY && x == destX) return cost;
		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			if (ny >= N || nx >= N || ny < 0 || nx < 0) continue;
			if (visited[ny][nx] || maze[ny][nx] == '1') continue;
			visited[ny][nx] = 1;
			q.push({ ny,nx,cost+1 });
		}
	}
	return INF;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'S' || maze[i][j] == 'K') {
				node.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < M + 1; i++) {
		parent[i] = i;
		for (int j = i + 1; j < M + 1; j++) { //모든 S, K 쌍들의 거리 구하기 
			int cost = calcDist(i, j);
			graph.push_back({ i,j,cost }); //노드 번호와 거리 저장
		}
	}
	sort(graph.begin(), graph.end());
	for (int i = 0; i < graph.size(); i++) {
		if (cnt == M) break;
		int a = graph[i].y;
		int b = graph[i].x;
		if (Find(a) != Find(b) && calcDist(a, b) != INF) {
			Union(a, b);
			cnt++;
			ans += graph[i].cost;
		}
	}
	if (cnt == M) cout << ans;
	else cout << -1;
	return 0;
}