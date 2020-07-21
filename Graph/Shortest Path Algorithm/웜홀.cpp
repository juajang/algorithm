#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> p;
int TC, N, M, W;
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> TC;
	while (TC--) {
		vector<p> G[501];
		int res[501];

		cin >> N >> M >> W;
		int S, E, T;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			//도로는 방향이 없음, 양방향 도로 
			G[S].push_back({ E,T });
			G[E].push_back({ S,T });
		}
		for (int i = 0; i < W; i++) {
			//웜홀은 단방향 
			cin >> S >> E >> T;
			G[S].push_back({ E,-T });
		}

		for (int i = 1; i <= N; i++) {
			res[i] = INF;
		}
		res[1] = 0;
		bool check = false;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < G[j].size(); k++) {
					int next = G[j][k].first;
					int nextCost = G[j][k].second;
					//사이클 형성이 되었는지만 알면 되기 때문에 시작점으로부터 단절된 두 정점 사이의 거리도 업데이트
					if (res[next] > res[j] + nextCost) {
						res[next] = res[j] + nextCost;
						//N번째에서 값이 갱신 -> 음의 사이클 존재, 시간이 되돌아 갈 수 있음을 의미 
						if (i == N) {
							check = true;
							break;
						}
					}
				}
			}
		}
		if (check) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}