#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int R, C, y, x, dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; //동 서 남 북 
int opDir[4] = { 1,0,3,2 }, ansY, ansX;
char map[26][26], ans = 'x';
char block[7] = { '|','-','+','1','2','3','4' };
bool visited[26][26];

int checkDir(char c, int dir) {
	//가스 배관이 | 이렇게 생겼으면 남북으로만 가스가 통할 수 있음 
	if (c == '|') {
		if (dir == 2 || dir == 3) return dir;
	}
	else if (c == '-') {
		if (dir == 0 || dir == 1) return dir;
	}
	else if (c == '+') return dir;
	else if (c == '1') {
		if (dir == 0 || dir == 2) return dir;
	}
	else if (c == '2') {
		if (dir == 0 || dir == 3) return dir;
	}
	else if (c == '3') {
		if (dir == 1 || dir == 3) return dir;
	}
	else if (c == '4') {
		if (dir == 1 || dir == 2) return dir;
	}
	return -1;
}

void dfs(int y, int x) {
	char now = map[y][x];
	if (ans != 'x') return;
	for (int i = 0; i < 4; i++) {
		//가스 배관에 따라 해당되는 방향만 검사한다. 그 방향이 비어있으면 문제가 있는 것 
		if (checkDir(now, i) == -1 && now != 'M') continue;
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (map[ny][nx] == '.') {
			for (int j = 0; j < 7; j++) {
				char b = block[j];
				bool chk = true;
				for (int k = 0; k < 4; k++) { //동<->서, 남<->북 각 방향대로 서로 연결되어 있다면
					int ky = ny + dir[k][0];
					int kx = nx + dir[k][1];
					int bDir = checkDir(b, k);
					int kDir = checkDir(map[ky][kx], opDir[k]);
					if ((bDir == -1 && kDir != -1) || (bDir != -1 && kDir == -1)) {
						chk = false;
						break;
					}
				}
				if (chk) {
					ansY = ny, ansX = nx;
					ans = b;
					break;
				}
			}
		}
		else if (!visited[ny][nx] && map[ny][nx] != '.') {
			visited[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}

int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'M') {
				y = i; x = j;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	visited[y][x] = true;
	dfs(y, x);
	printf("%d %d %c", ansY, ansX, ans);
	return 0;
}