#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, P;
const int INF = 0x3f3f3f3f;
int gen[17][17], cache[1<<17];

int fix(int cur, int visited) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (visited & (1 << i)) cnt++;
	}
	if (cnt >= P) return 0;

	int& ret = cache[visited];
	if (ret != -1) return ret;
	ret = INF; 
	//안 고친 발전기를 고친 발전기를 이용해서 고치기 
	for (int next = 0; next < N; next++) {
		if (visited & (1 << next)) continue;
		int cost = INF;
		//현재 켜진 발전기 중 최소비용을 선택
		for (int i = 0; i < N; i++) {
			if (!(visited & (1 << i))) continue;
			cost = min(cost, gen[i][next]);
		}
		ret = min(ret, fix(next, visited | (1 << next)) + cost);
	}
	return ret;
	
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> gen[i][j];
		}
	}
	string str;
	int start = 0, cnt = 0;
	cin >> str >> P;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'Y') {
			start = start | (1 << i);
			cnt++;
		}
	}
	int ans = INF;
	if (P == 0) ans = 0;
	if (cnt >= P) ans = 0; 
	else {
		for (int i = 0; i < N; i++) {
			if (str[i] == 'N') ans = min(fix(i, start), ans);
		}
		if (ans == INF) ans = -1;
	}
	cout << ans << "\n";
	return 0;
}