#include <iostream>
#include <vector>
using namespace std;

int N, M, city[51][51], s[13];
int chk = 0, ans = 0x3f3f3f;

typedef pair<int, int> p;
vector<p> chicken;
vector<p> house;

int min(int a, int b) { return a < b ? a : b; }

//chk개 중에서 M개 뽑았을 때 치킨 거리 최솟값 
void dfs(int cnt, int idx) {
	if (cnt == M) {
		//각각의 집에 대해서 치킨 거리를 구한다 
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int MIN = 0x3f3f3f;
			for (int j = 0; j < M; j++) {
				int dist = abs(chicken[s[j]].first - house[i].first) + abs(chicken[s[j]].second - house[i].second);
				MIN = min(dist, MIN);
			}
			sum += MIN;
		}
		ans = min(sum, ans);
	}
	for (int i = idx; i < chicken.size(); i++) {
		s[cnt] = i;
		dfs(cnt + 1, i + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 2) chicken.push_back({ i,j });
			if (city[i][j] == 1) house.push_back({ i,j });
		}
	}
	dfs(0, 0);
	cout << ans << "\n";
	return 0;
}