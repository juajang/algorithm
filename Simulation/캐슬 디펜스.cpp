#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, D, a[15], ans = 0;
vector<vector<int>> map(16, vector<int>(16, 0));
vector<pair<int, int>> enemy;

int getDist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int attack(vector<vector<int>> map, int a[]) {
	int cnt = 0;
	while (true) {
		bool fin = true;
		for (int i = 0; i < 3; i++) {
			int aX = a[i], aY = N, eY = -1, eX = 100;
			int dist = D; 
			for (int j = N - 1; j >= 0; j--) {
				for (int k = 0; k < M; k++) {
					int tmp = getDist(aY, aX, j, k);
					if (map[j][k] && tmp < dist) {
						dist = tmp;
						eY = j; eX = k;
					}
					if (map[j][k] && tmp == dist && k < eX) {
						dist = tmp;
						eY = j; eX = k;
					}
				}
			}
			if(eY != -1) enemy.push_back(make_pair(eY, eX));
		}
		for (int i = 0; i < enemy.size(); i++) {
			int eY = enemy[i].first;
			int eX = enemy[i].second;
			if (map[eY][eX]) {
				cnt++;
				map[eY][eX] = 0;
			}
		}
		enemy.clear();
		vector<vector<int>> newMap(16, vector<int>(16, 0));
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < M; j++) {
				newMap[i][j] = map[i-1][j];
				if (newMap[i][j]) {
					fin = false;
				}
			}
		}
		map = newMap;
		if (fin) break;
	}
	return cnt;
}

void dfs(int cnt, int idx) {
	if (cnt == 3) {
		ans = max(ans, attack(map, a));
		return;
	}
	for (int i = idx; i < M; i++) {
		a[cnt] = i;
		dfs(cnt + 1, i + 1);
	}
}

int main() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];		
		}
	}
	dfs(0, 0);
	cout << ans << "\n";
	return 0;
}