#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100010;
int N, K, M, cost[MAX + 1000];
vector<int> graph[MAX + 1000];
queue<int> Q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K >> M;
	for (int i = 1; i <= M; i++) {
		int n;
		for (int j = 0; j < K; j++) {
			cin >> n;
			graph[n].push_back(i + N);
			graph[i + N].push_back(n);
		}
	}

	Q.push(1);
	cost[1] = 1;
	int answer = -1;

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();

		if (now == N) {
			answer = cost[now];
			break;
		}
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			//방문하지 않은 역인 경우
			if (cost[next] == 0) { 
				//하이퍼큐브인 경우 cost는 그대로 
				if (next > N) cost[next] = cost[now];
				//역인 경우 
				else cost[next] = cost[now] + 1;
				Q.push(next);
			}
		}
	}

	cout << answer;
	return 0;
}