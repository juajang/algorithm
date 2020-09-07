#include <iostream>
#include <vector>
#include <string.h>
#define MAX 100010
#define MAX_STEP 17 // 2^k >= MAX인 최소의 k는 16

using namespace std;

int N, ant[MAX], Next[MAX][MAX_STEP], Cost[MAX][MAX_STEP];
vector<pair<int, int>> graph[MAX];
bool visited[MAX];

//그래프 탐색, 연결 상태 확인
void DFS(int here) {
	visited[here] = true;

	for (auto& n : graph[here]) {
		if (visited[n.first]) continue;

		Next[n.first][0] = here;
		Cost[n.first][0] = n.second;

		DFS(n.first);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ant[i];
	}

	int a, b, c;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	memset(visited, false, sizeof(visited));
	memset(Next, 0, sizeof(Next));
	memset(Cost, 0, sizeof(Cost));

	DFS(1);
	Next[1][0] = 1;
	Cost[1][0] = 0;

	//희소 테이블, Next[i][j]: i에서 시작해서 2^j번 건넜을 때의 정점
	for (int j = 1; j < MAX_STEP; j++) {
		for (int i = 1; i <= N; i++) {
			//2^j번 이동 = 2^(j-1)번*2번 이동
			Next[i][j] = Next[Next[i][j - 1]][j - 1];
			Cost[i][j] = Cost[i][j - 1] + Cost[Next[i][j - 1]][j - 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		int step = i;
		for (int j = MAX_STEP - 1; j >= 0; j--) {
			// 굴을 건널 수 있는 에너지가 있는 경우에만 건너뛴다.
			if (Cost[step][j] > ant[i]) continue;

			ant[i] -= Cost[step][j];
			step = Next[step][j];
		}
		cout << step << "\n";
	}

	return 0;
}