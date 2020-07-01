#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

char map[12][6];
bool visited[12][6];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int ans = 0;

vector<pair<int, int>> POP; 

void getSameColor(int y, int x) {
	POP.push_back(make_pair(y, x));
	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (ny >= 12 || ny < 0 || nx >= 6 || nx < 0) continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] == map[y][x]) {
			visited[ny][nx] = true;
			getSameColor(ny, nx);
		}
	}
}

int main() {
	string str;
	for (int i = 0; i < 12; i++) {
		cin >> str;
		for (int j = 0; j < 6; j++) {
			map[i][j] = str[j];
		}
	}
	while (true) {
		memset(visited, false, sizeof(visited));
		bool finish = true;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && !visited[i][j]){
					visited[i][j] = true;
					getSameColor(i, j);
					if (POP.size() >= 4) {
						finish = false;
						for (int k = 0; k < POP.size(); k++) {
							int py = POP[k].first;
							int px = POP[k].second;
							map[py][px] = '.';
						}
					}
					POP.clear();
				}
			}
		}
		for (int i = 10; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] == '.') continue;
				int idx = i;
				while (idx != 11 && map[idx + 1][j] == '.') {
					map[idx + 1][j] = map[idx][j];
					map[idx][j] = '.';
					idx++;
				}
			}
		}
		if (finish) break;
		else ans++;
	}
	cout << ans << "\n";
	return 0;
}