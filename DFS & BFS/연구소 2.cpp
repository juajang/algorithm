#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

typedef pair<int, int> p;
const int INF = 0x3f3f3f3f;
int ans = INF;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N, M, map[50][50];
bool visited[50][50];
vector<p> virus, s;
queue<p> Q;

void BFS() {
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < M; i++) {
		int y = s[i].first;
		int x = s[i].second;
		Q.push({ y,x });
		visited[y][x] = true;
	}

	int dayCount = 0;

	while (!Q.empty()) {
		int qsize = Q.size();

		for (int i = 0; i < qsize; i++) {
			int y = Q.front().first;
			int x = Q.front().second;
			Q.pop();

			for (int j = 0; j < 4; j++) {
				int ny = y + dir[j][0];
				int nx = x + dir[j][1];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
				if (map[ny][nx] == 1 || visited[ny][nx]) continue;
				visited[ny][nx] = true;
				Q.push({ ny,nx });
			}

		}
		//실제로 옮긴 바이러스가 있을때만 count++
		if (!Q.empty()) dayCount++;
	}

	bool check = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 1 && visited[i][j] == false) {
				check = false;
				break;
			}
		}
		if (check == false) break;
	}

	if (check) ans = min(dayCount, ans);
}

//조합: 바이러스 초기 위치 선택하기 
void selectVirus(int cnt, int idx) {
	if (cnt == M) {
		BFS();
		return;
	}
	for (int i = idx; i < virus.size(); i++) {
		int y = virus[i].first;
		int x = virus[i].second;
		s.push_back({ y,x });
		selectVirus(cnt + 1, i + 1);
		s.pop_back();
	}
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back({ i,j });
		}
	}
	selectVirus(0, 0);

	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
