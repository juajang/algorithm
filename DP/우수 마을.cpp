#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 10010;
int N, pop[MAX], cache[2][MAX];
vector<int> G[MAX];

int DP(int now, int prev, bool isSelected) {
	int& ret = cache[isSelected][now];
	if (ret != -1) return ret;

	ret = isSelected ? pop[now] : 0;

	for (auto& next : G[now]) {
		//tree 자료구조: 이전에 왔었던 방향으로는 X 
		if (next == prev) continue;

		//현재 마을이 우수 마을인 경우, 인접한 마을은 우수 마을이 아님 
		if (isSelected) {
			ret += DP(next, now, false);
		}

		//현재 마을이 일반 마을인 경우, 인접한 마을은 우수 마을이거나 일반 마을
		else {
			ret += max(DP(next, now, true), DP(next, now, false));
		}
	}
	return ret; 
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> pop[i];
	}
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	memset(cache, -1, sizeof(cache));

	int ans = max(DP(1, 1, true), DP(1, 1, false));
	cout << ans << endl;

	return 0;
}