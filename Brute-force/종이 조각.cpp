#include <iostream>
using namespace std;

int N, M, rec[4][4];
bool selected[4][4];
int ans = 0;

int max(int a, int b) { return a > b ? a : b; }

int sum() {
	int res = 0, sum = 0;

	//가로로 자른 종이의 합 구하기 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (selected[i][j] == true) {
				sum = (sum * 10) + rec[i][j];
			}
			else {
				res += sum;
				sum = 0;
			}
		}
		res += sum;
		sum = 0;
	}

	//세로로 자른 종이의 합 구하기
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (selected[j][i] == false) {
				sum = (sum * 10) + rec[j][i];
			}
			else {
				res += sum;
				sum = 0;
			}
		}
		res += sum;
		sum = 0;
	}
	return res;
}

//완전 탐색
void dfs(int x, int y) {
	//끝까지 모두 선택한 경우: sum 구하기
	if (x == N) {
		ans = max(ans, sum());
		return;
	}

	//가로 끝까지 온 경우 세로 + 1;
	if (y == M) {
		dfs(x + 1, 0);
		return;
	}

	//두 가지 경우: 가로로 자르거나, 세로로 자르거나 
	selected[x][y] = true;
	dfs(x, y + 1);
	selected[x][y] = false;
	dfs(x, y + 1);
}

int main() {
	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			rec[i][j] = str[j] - '0';
		}
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}