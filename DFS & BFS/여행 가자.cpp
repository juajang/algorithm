#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

const int MAX = 201;
int N, M, course[1000];
bool MAP[MAX][MAX], visited[1000];
bool answer = true;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> course[i];
	}
	for (int i = 1; i < M; i++) {
		memset(visited, 0, sizeof(visited));
		int start = course[i - 1];
		int end = course[i];
		queue<int> Q;
		Q.push({ start });
		bool isPossible = false;
		while (!Q.empty()) {
			int now = Q.front();
			visited[now] = true;
			Q.pop();
			if (now == end) {
				isPossible = true;
				break;
			}
			for (int i = 1; i <= N; i++) {
				if (MAP[now][i] && !visited[i]) Q.push({ i });
			}
		}
		if (!isPossible) {
			answer = false;
			break;
		}
	}
	if (answer) cout << "YES";
	else cout << "NO";
	return 0;
}

