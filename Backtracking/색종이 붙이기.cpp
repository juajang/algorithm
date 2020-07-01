#include <iostream>
#include <string.h>
using namespace std;

int paper[10][10], colorPaper[6] = { 0, 5, 5, 5, 5, 5 };
int ans = 100;

void fill(int y, int x, int len, int val) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			paper[y + i][x + j] = val;
		}
	}
}

bool check(int y, int x, int len) {
	if (y + len > 10 || x + len > 10) return false;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (!paper[y + i][x + j]) return false;
		}
	}
	return true;
}

void dfs(int idx, int cnt) {
	if (idx == 100) { 
		//채울 필요가 없었다면 그냥 건너뛰고, 채워야 하는 공간은 모두 채워야지만 여기까지 올 수 있음 
		if (ans > cnt) ans = cnt;
		return;

	}
	int y = idx / 10;
	int x = idx % 10;
	if (ans <= cnt) return;
	if (!paper[y][x]) dfs(idx + 1, cnt);
	else {
		//메꿀 공간이 있는데 어떤 크기의 색종이로도 불가능하다면 더 이상 탐색 X
		for (int i = 5; i > 0; i--) {
			if (colorPaper[i] > 0) {
				if (check(y, x, i)) {
					fill(y, x, i, 0);
					colorPaper[i]--;
					dfs(idx + 1, cnt + 1);
					fill(y, x, i, 1);
					colorPaper[i]++;
				}
			}
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> paper[i][j];
		}
	}
	dfs(0, 0);
	cout << (ans == 100 ? -1 : ans) << "\n";
	return 0;
}