#include <iostream>
#include <string.h>
using namespace std;

int N, M, answer = 0;
char maze[500][500];
int cache[500][500];

bool dfs(int x, int y) {
	//미로를 탈출할 수 있는 경우 
	if (x < 0 || x >= N || y < 0 || y >= M) return true;

	int& ret = cache[x][y];
	if (ret != -1) return ret; //중복 탐색 방지 

	//미로를 탐색하다가 결국 탐색 전 0으로 초기해놨었던 처음 출발 위치로 돌아오게 됐다는 것은 탈출이 불가능한 위치라는 것을 의미한다.  
	ret = 0;
	if (maze[x][y] == 'U') {
		ret = dfs(x - 1, y);
	}
	else if (maze[x][y] == 'R') {
		ret = dfs(x, y + 1);
	}
	else if (maze[x][y] == 'D') {
		ret = dfs(x + 1, y);
	}
	else if (maze[x][y] == 'L') {
		ret = dfs(x, y - 1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
		}
	}

	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dfs(i, j)) answer++;
		}
	}
	cout << answer;
	return 0;
}
